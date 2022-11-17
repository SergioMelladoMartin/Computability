#include "../lib/grammar.h"

/**
 * @brief Construct a new Grammar:: Grammar object
 * 
 * @param alphabet 
 * @param productions 
 * @param nonterminals 
 * @param start_symbol 
 */
Grammar::Grammar(Alphabet alphabet, std::set<Production> productions, std::set<Symbol> nonterminals, Symbol start_symbol) {
    alphabet_ = alphabet;
    productions_ = productions;
    nonterminals_ = nonterminals;
    start_symbol_ = start_symbol;
}

/**
 * @brief Return the grammar in a more readable format
 * 
 * @return std::string 
 */
std::string Grammar::print() {
    //print the grammar
    std::string grammar = "";
    grammar += "Alphabet: " + alphabet_.print();
    grammar += "Productions:\n";
    for (auto production : productions_) {
        grammar += production.print();
    }
    grammar += "Nonterminals: { ";
    for (auto nonterminal : nonterminals_) {
        grammar += nonterminal.get_symbol()  + " ";
    }
    grammar += "}\nStart symbol: " + start_symbol_.get_symbol();
    return grammar;
}

/**
 * @brief Print the grammar formated
 * 
 * @return std::string 
 */
std::string Grammar::printFormated() {
    std::string grammar = "";

    grammar += std::to_string(this->alphabet_.size()) + "\n";
    for (auto symbol: this->alphabet_.get_alphabet()) {
        grammar += symbol.get_symbol() + "\n";
    }

    grammar += std::to_string(this->nonterminals_.size()) + "\n";
    for (auto symbol: this->nonterminals_) {
        grammar += symbol.get_symbol() + "\n";
    }

    grammar += start_symbol_.get_symbol() + "\n";

    grammar += std::to_string(this->productions_.size()) + "\n";
    for (auto production: this->productions_) {
        grammar += production.print();
    }

    return grammar;
}
