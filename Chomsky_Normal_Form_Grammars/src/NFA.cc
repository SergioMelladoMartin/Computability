#include "../lib/NFA.h"

/**
 * @brief Construct a new NFA::NFA object
 * 
 * @param alphabet 
 * @param initialState 
 * @param transitions 
 * @param states 
 */
NFA::NFA(Alphabet alphabet, int initialState, std::vector<std::tuple<int, Symbol, int>> transitions, std::vector<State> states) {
  this->alphabet = alphabet;
  this->initialState = initialState;
  this->transitions = transitions;
  this->states = states;
}

/**
 * @brief e-closure of a set of states
 * 
 * @param states 
 * @return std::set<State> 
 */
std::set<State> NFA::e_closure(std::set<State> states) {
  std::set<State> current_states = states;
  std::set<State> new_states = states;
  bool changed = true;
  while (changed) {
    for (auto state: current_states) {
      for (std::tuple<int, Symbol, int> transition: this->transitions) {
        if (std::get<0>(transition) == state.getId() && std::get<1>(transition) == EMPTY_SYMBOL) {
          new_states.insert(this->states[std::get<2>(transition)]);
        }
      }  
    }

    if (new_states.size() == current_states.size()) {
      changed = false;
    } 

    current_states = new_states;
  }

  return current_states;
}

/**
 * @brief Check if a chain is accepted by the NFA
 * 
 * @param chain 
 * @return true 
 * @return false 
 */
bool NFA::is_accepted(Chain chain) {
  std::set<State> currentStates;
  currentStates.insert(this->states[this->initialState]);

  currentStates = this->e_closure(currentStates);

  for (Symbol symbol: chain.getChain()) {
    std::set<State> nextStates;
      for (State state: currentStates) {
        for (std::tuple<int, Symbol, int> transition: this->transitions) {
          if (std::get<0>(transition) == state.getId() && std::get<1>(transition) == symbol) {
            nextStates.insert(this->states[std::get<2>(transition)]);
          }
        }
      }
    currentStates = this->e_closure(nextStates);
  }

  for (State state: currentStates) {
    if (state.isFinalState()) {
      return true;
    }
  }

  return false;
}

/**
 * @brief Get the death states of the NFA
 * 
 * @return std::string 
 */
std::string NFA::deathStates() {
  std::string result = "Los estados { ";
  for (State state: this->states) {
    bool isDeath = true;
    for (std::tuple<int, Symbol, int> transition: this->transitions) {
      if (std::get<0>(transition) == state.getId() && std::get<2>(transition) != state.getId()) {
        isDeath = false;
      } 
    }

    if ((isDeath) && (!state.isFinalState())) {
      result += std::to_string(state.getId()) + " ";
    }
  }

  result += "} son estados de muerte";
  return result;
}

/**
 * @brief  Return true if the NFA is a DFA
 * 
 * @return true 
 * @return false 
 */
bool NFA::isDFA() {
  for (State state: this->states) {
    for (Symbol symbol: this->alphabet.get_alphabet()) {
      int count = 0;
      for (std::tuple<int, Symbol, int> transition: this->transitions) {
        if (std::get<0>(transition) == state.getId() && std::get<1>(transition) == symbol) {
          count++;
        }
      }

      if (count != 1) {
        return false;
      }
    }
  }

  return true;
}

/**
 * @brief Convert a number in a letter
 * 
 * @return Grammar 
 */
std::string NFA::numberToLetter(int number) {
  //convert number is a capital letter
  std::string letter = "";
  letter += (char)(number + 65);
  return letter;
}

/**
 * @brief Convert the NFA to a Grammar if it is a DFA
 * 
 * @return Grammar 
 */
Grammar NFA::toGrammar() {
  if (!this->isDFA()) {
    std::cout << "El autómata no es un DFA. No se puede aplicar el algoritmo de conversión." << std::endl;
    exit(1);
  }

  Alphabet alphabet = this->alphabet;
  std::set<Symbol> non_terminals;
  std::set<Production> productions;
  Symbol initial_symbol = Symbol(this->numberToLetter(this->initialState));

  for (State state: this->states) {
    non_terminals.insert(Symbol(this->numberToLetter(state.getId())));
  }

  for (std::tuple<int, Symbol, int> transition: this->transitions) {
    Symbol left = Symbol(this->numberToLetter(std::get<0>(transition)));
    std::vector<Symbol> right = {Symbol(std::get<1>(transition)), Symbol(this->numberToLetter(std::get<2>(transition)))};
    Production production = Production(left, {right});
    productions.insert(production);
  }

  for (State state: this->states) {
    if (state.isFinalState()) {
      Symbol left = Symbol(this->numberToLetter(state.getId()));
      Symbol right = EMPTY_SYMBOL;
      Production production = Production(left, {right});
      productions.insert(production);
    }
  }

  Grammar grammar = Grammar(alphabet, productions, non_terminals, initial_symbol);
  return grammar;
}