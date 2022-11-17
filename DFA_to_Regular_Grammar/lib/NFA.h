#pragma once

#include "alphabet.h"
#include "state.h"
#include "symbol.h"
#include "chain.h"
#include "production.h"
#include "grammar.h"

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <tuple>

/**
 * @brief NFA class
 * 
 */
class NFA {
  public:
    NFA(Alphabet, int, std::vector<std::tuple<int, Symbol, int>>, std::vector<State>);

    bool is_accepted(Chain);
    std::string deathStates();
    Grammar toGrammar();
    bool isDFA();

  private:
    Alphabet alphabet;
    int initialState;
    std::vector<std::tuple<int ,Symbol, int>> transitions;
    std::vector<State> states;

    std::set<State> e_closure(std::set<State>);
    std::string numberToLetter(int);

};


