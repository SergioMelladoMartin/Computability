#pragma once
#include <set>

#include "production.h"
#include "symbol.h"
#include "alphabet.h"

class Grammar {
  public:
    Grammar(Alphabet, std::set<Production>, std::set<Symbol>, Symbol);

    std::string print();
    std::string printFormated();

  private: 
    Alphabet alphabet_;
    std::set<Production> productions_;
    std::set<Symbol> nonterminals_;
    Symbol start_symbol_;
};