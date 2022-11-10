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


