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


Grammar::Grammar(Alphabet alphabet, Chain chain) {
    alphabet_ = alphabet;

    Symbol start_symbol = Symbol("S");
    start_symbol_ = start_symbol;

    std::set<Symbol> nonterminals;
    nonterminals.insert(start_symbol);
    nonterminals.insert(Symbol("X"));

    std::set<Production> productions;

    Symbol left_side = start_symbol;
    std::vector<Symbol> right_side = chain.getChain();
    right_side.push_back(Symbol("X"));
    productions.insert(Production(left_side, right_side));

    for (Symbol symbol: alphabet.get_alphabet()) {
        Symbol left_side = Symbol("X");
        std::vector<Symbol> right_side;
        right_side.push_back(symbol);
        Production production = Production(left_side, right_side);
        productions.insert(production);
    }

    productions_ = productions;
    nonterminals_ = nonterminals;
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

void Grammar::removeEmptyProductions() {
    for (auto production : productions_) {
        if (production.left_hand_side() == start_symbol_) {
            continue;
        }

        for (auto symbol : production.right_hand_side()) {
            if (symbol == EMPTY_SYMBOL) {
                productions_.erase(production);
            }
        }
    }

    std::cout << "[TRAZA] - Eliminación de producciones vacías" << std::endl;
    for (auto production : productions_) {
        std::cout << production.print();
    }
}

void Grammar::removeUnitProductions() {
  bool stop = false;
  std::vector<Production> new_productions;
  while (!stop) {
    stop = true;
    for (auto production: this->productions_) {
      if (production.right_hand_side().size() == 1 
        && (this->isNonTerminal(production.right_hand_side()[0]))) { 
          std::cout<< production.left_hand_side().get_symbol() << " -> " << production.right_hand_side()[0].get_symbol() << std::endl;
          Symbol left_hand_side = production.left_hand_side();
          Symbol symbol = production.right_hand_side()[0];
                
          for (auto production2: this->productions_) {
            if (production2.left_hand_side() == symbol) {
              std::vector<Symbol> right_hand_side = production2.right_hand_side();
              new_productions.push_back(Production(left_hand_side, right_hand_side));
              stop = false;
            }
          }
        this->productions_.erase(production);
      }
    }
  }

  for (auto production: new_productions) {
    this->productions_.insert(production);
  }

  std::cout << "\n\n[TRAZA] - Eliminación de las producciones unitarias\n";
  for (auto production: this->productions_) {
    std::cout << production.print();
  }
}


std::string Grammar::toCapitalLetter(std::string symbol) {
    std::string capitalLetter = "";
    capitalLetter += toupper(symbol[0]);
    return capitalLetter;
}

bool Grammar::isNonTerminal(Symbol symbol) {
    for (auto nonterminal: this->nonterminals_) {
        if (nonterminal == symbol) {
            return true;
        }
    }
    return false;
}

void Grammar::FNC() {
    this->removeEmptyProductions();
    this->removeUnitProductions();

    for (auto symbol: this->alphabet_.get_alphabet()) {
        Symbol left_hand_side = Symbol(this->toCapitalLetter(symbol.get_symbol()) + "'");
        std::vector<Symbol> right_hand_side = {symbol};
        this->productions_.insert(Production(left_hand_side, right_hand_side));	
        this->nonterminals_.insert(left_hand_side);
    } 

    for (auto production: this->productions_) {
        if (production.right_hand_side().size() > 1) {
            Symbol left_hand_side = production.left_hand_side();
            std::vector<Symbol> right_hand_side = production.right_hand_side();
            this->productions_.erase(production);
            std::vector<Symbol> new_right_hand_side;
            for (auto symbol: right_hand_side) {
                if (!(this->nonterminals_.find(symbol) != this->nonterminals_.end())) {
                    new_right_hand_side.push_back(Symbol(this->toCapitalLetter(symbol.get_symbol()) + "'"));
                } else {
                    new_right_hand_side.push_back(symbol);
                }   
            }
            this->productions_.insert(Production(left_hand_side, new_right_hand_side));
        }
    }

    int n = 0;
    std::vector<Production> new_productions;
    std::vector<Production> productions_to_remove;
    for (auto production: this->productions_) {
        if (production.right_hand_side().size() > 2) {
            Symbol left_hand_side = production.left_hand_side();
            std::vector<Symbol> right_hand_side;
            right_hand_side.push_back(production.right_hand_side()[0]);
            right_hand_side.push_back(Symbol("D" + std::to_string(n)));
            new_productions.push_back(Production(left_hand_side, right_hand_side));
            this->nonterminals_.insert(Symbol("D" + std::to_string(n)));

            for (auto i = 1; i < production.right_hand_side().size() - 1; ++i) {
                Symbol left_hand_side = Symbol("D" + std::to_string(n));
                std::vector<Symbol> right_hand_side;
                if (i == production.right_hand_side().size() - 2) {
                    right_hand_side.push_back(production.right_hand_side()[i]);
                    right_hand_side.push_back(production.right_hand_side()[i + 1]);
                } else {
                    right_hand_side.push_back(production.right_hand_side()[i]);
                    right_hand_side.push_back(Symbol("D" + std::to_string(n + 1)));
                    this->nonterminals_.insert(Symbol("D" + std::to_string(n + 1)));
                }
                new_productions.push_back(Production(left_hand_side, right_hand_side));
                ++n;
            }

            productions_to_remove.push_back(production);
        }
    }

    for (auto production: new_productions) {
        this->productions_.insert(production);
    }

    for (auto production: productions_to_remove) {
        this->productions_.erase(production);
    }

    std::cout << "\n\n[TRAZA] - FNC\n";
    for (auto production: this->productions_) {
        std::cout << production.print();
    }
}
