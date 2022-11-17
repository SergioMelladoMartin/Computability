#pragma once 
#include <vector>

#include "symbol.h"

class Production {
  public:
    Production(Symbol, std::vector<Symbol>);

    Symbol left_hand_side() const;
    std::vector<Symbol> right_hand_side() const;

    std::string print();

    bool operator< (const Production&) const;

  private:
    Symbol left_hand_side_;
    std::vector<Symbol> right_hand_side_;
};