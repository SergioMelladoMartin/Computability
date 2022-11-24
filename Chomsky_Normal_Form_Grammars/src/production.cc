#include "../lib/production.h"

Production::Production(Symbol left_hand_side, std::vector<Symbol> right_hand_side) {
    this->left_hand_side_ = left_hand_side;
    this->right_hand_side_ = right_hand_side;
}

Symbol Production::left_hand_side() const {
    return left_hand_side_;
}

std::vector<Symbol> Production::right_hand_side() const {
    return right_hand_side_;
}

std::string Production::print() {
    std::string production = left_hand_side_.get_symbol() + " -> ";
    for (auto symbol : right_hand_side_) {
        production += symbol.get_symbol();
    }
    production += "\n";
    return production;
}

bool Production::operator< (const Production& production) const {
    if (this->left_hand_side_ < production.left_hand_side_)
        return true;
    else if (this->left_hand_side_ == production.left_hand_side_) {
        if (this->right_hand_side_ < production.right_hand_side_)
            return true;
        else
            return false;
    }
    else
        return false;
}