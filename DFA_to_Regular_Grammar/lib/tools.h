#include "alphabet.h"
#include "state.h"
#include "NFA.h"
#include "symbol.h"
#include "chain.h"

#include <iostream>

/**
 * @brief Split a string by a separator
 * 
 * @param line 
 * @param separator 
 * @return std::vector<std::string> 
 */
std::vector<std::string> split(std::string line, const char separator) {
  std::vector<std::string> line_splited;
  std::string word;

  for(auto i = 0; i < line.size(); ++i) {
    if(line[i] == separator){
      line_splited.push_back(word);
      word.clear();
    } else {
      word.push_back(line[i]);
    }
  }

  line_splited.push_back(word);
  return line_splited;
};


/**
 * @brief Read a file and return a NFA
 * 
 * @param filename 
 * @return std::vector<std::string> 
 */
NFA readNFA(std::string file) {
  std::ifstream input(file);

  std::string line;
  std::getline(input, line);
  std::vector<std::string> symbols = split(line, ' ');
  Alphabet alphabet;
  for (std::string symbol : symbols) {
    alphabet.insert_symbol(Symbol(symbol));
  }

  std::getline(input, line);
  int num_states = std::stoi(line);

  std::getline(input, line);
  int initial_state = std::stoi(line);

  std::vector<State> states;
  std::vector<std::tuple<int, Symbol, int>> transitions;
  for (int i = 0; i < num_states; ++i) {
    std::getline(input, line);
    std::vector<std::string> state_info = split(line, ' ');
    
    int id = std::stoi(state_info[0]);
    bool is_final = std::stoi(state_info[1]);
    states.push_back(State(id, is_final));

    for (int j = 3; j < state_info.size(); j += 2) {
      int next_state = std::stoi(state_info[j + 1]);
      Symbol symbol = Symbol(state_info[j]);
      transitions.push_back(std::make_tuple(id, symbol, next_state));
    }

  }

  return NFA(alphabet, initial_state, transitions, states);
}


/**
 * @brief Read a string and return a chain
 * 
 * @param line 
 * @return Chain 
 */
Chain readChain(std::string line) {
  //create a std::vector<std::string> with the symbols of the chain with a loop
  std::vector<std::string> symbols;
  for (int i = 0; i < line.size(); ++i) {
    symbols.push_back(std::string(1, line[i]));
  }


  Alphabet alphabet;
  std::vector<Symbol> chain;
  for (std::string symbol : symbols) {
    alphabet.insert_symbol(Symbol(symbol));
    chain.push_back(Symbol(symbol));
  }

  return Chain(chain, alphabet);
}