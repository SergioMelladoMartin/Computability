#pragma once
#include <set>

#include "production.h"
#include "symbol.h"
#include "alphabet.h"
#include "chain.h"

class Grammar {
  public:
    Grammar(Alphabet, std::set<Production>, std::set<Symbol>, Symbol);
    Grammar(Alphabet, Chain);

    std::string print();
    std::string printFormated();

    void removeEmptyProductions();
    void removeUnitProductions();
    void FNC();

  private: 
    Alphabet alphabet_;
    std::set<Production> productions_;
    std::set<Symbol> nonterminals_;
    Symbol start_symbol_;

    std::string toCapitalLetter(std::string);
    bool isNonTerminal(Symbol);
};