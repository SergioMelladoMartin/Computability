//Universidad de La Laguna
//Escuela Superior de Ingeniería y Tecnología
//Grado en Ingeniería Informática
//Asignatura: Computabilidad y Algoritmia
//Curso: 2o
//Práctica 2: Símbolos, cadenas y alfabetos
//Autor: Sergio Mellado Martín
//Correo: alu0101326351@ull.edu.es
//Fecha: 28/09/2022
//Archivo: chain.h
//         Declaración de los métodos de la clase chain.
#include "../lib/chain.h"

/**
 * @brief Construct a new Chain:: Chain object
 * 
 * @param chain 
 * @param alphabet 
 */
Chain::Chain(std::vector<Symbol> chain, Alphabet alphabet) {
  this->chain_ = chain;
  this->alphabet_ = alphabet;
  this->size_ = chain.size();

  if (chain.size() == 1 && chain[0] == Symbol("&")) {
    this->size_ = 0;
  }

}

std::vector<Symbol> Chain::getChain() const {
  return this->chain_;
}

/**
 * @brief Construct a new Chain:: Chain object
 * 
 * @param alphabet 
 */
Chain::Chain(Alphabet alphabet) {
  this->alphabet_ = alphabet;
  this->size_ = 0;
}

void Chain::insert(Symbol symbol) {
  this->chain_.push_back(symbol);
  this->size_++;
}

/**
 * @brief Devuelve la longitud de la cadena
 * 
 * @return int 
 */
int Chain::size() const {
    return this->size_;
}

/**
 * @brief Devuelve el alfabeto sobre el que se formo la cadena
 * 
 * @return Alphabet 
 */
Alphabet Chain::get_alphabet() {
  return this->alphabet_;
}

/**
 * @brief Devuelve un string con la cadena correctamente formateada
 * 
 * @return std::string 
 */
std::string Chain::print() const{
  std::string out = "";
  out += "[ ";
  if (this->size_ == 0) {
    out += "&";
  } else {
    for (auto i = 0; i < this->size(); ++i) {
      out += this->chain_[i].get_symbol(); 
    }
  }

  return out + " ]";
}

/**
 * @brief Devuelve la inversa de la cadena
 * 
 * @return Chain 
 */
Chain Chain::reverse() const{
  Chain reverse(this->alphabet_);
  for (auto i = this->size() - 1; i >= 0; --i) {
    reverse.insert(this->chain_[i]);
  }  

  return reverse;
}

/**
 * @brief Devuelve un vector con los prefijos de la cadena
 * 
 * @return std::vector<Chain> 
 */
std::vector<Chain> Chain::prefix() {
  std::vector<Chain> prefix;
  Chain empty_chain({EMPTY_SYMBOL}, this->alphabet_);
  prefix.push_back(empty_chain);

  for(auto i = 0; i < chain_.size(); ++i) {
    auto begin = chain_.begin();
    auto end = chain_.begin() + i + 1;
    std::vector<Symbol> slice(begin, end);

    Chain chain(slice, this->alphabet_);
    prefix.push_back(chain);
  }

  return prefix;
}

/**
 * @brief Devuelve un vector con los sufijos de la cadena
 * 
 * @return std::vector<Chain> 
 */
std::vector<Chain> Chain::sufix() {
  std::vector<Chain> sufix;
  Chain empty_chain({EMPTY_SYMBOL}, this->alphabet_);
  sufix.push_back(empty_chain);

  for(auto i = 0; i < chain_.size(); ++i) {
    auto begin = chain_.end() - i - 1;
    auto end = chain_.end();
    std::vector<Symbol> slice(begin, end);

    Chain chain(slice, this->alphabet_);
    sufix.push_back(chain);
  }

  return sufix;
}

/**
 * @brief Devuelve un vector con las subcadenas de la cadena
 * 
 * @return std::vector<Chain> 
 */
std::vector<Chain> Chain::subchains() {
  std::vector<Chain> subchains;
  Chain empty_chain({EMPTY_SYMBOL}, this->alphabet_);
  subchains.push_back(empty_chain);

  for(auto i = 0; i < chain_.size(); ++i){
    for(auto j = 0; j < chain_.size() - i; ++j){
        auto begin = chain_.begin() + j;
        auto end = chain_.begin() + i + j + 1;
        std::vector<Symbol> slice(begin, end);

        Chain chain(slice, this->alphabet_);
        subchains.push_back(chain);
    
    }
  }

  return subchains;
}

/**
 * @brief Concatenación de cadenas
 * 
 * @param other 
 * @return Chain 
 */
Chain Chain::concat(Chain other) const{
  Chain concat(this->chain_, this->alphabet_);
  for (auto i = 0; i < other.size(); ++i) {
    concat.insert(other[i]);
  }
  return concat;
}

/**
 * @brief Operador[]
 * 
 * @param i 
 * @return Symbol 
 */
Symbol Chain::operator[](int i) {
  return this->chain_[i];
}

/**
 * @brief Operador < 
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool Chain::operator< (const Chain& other) const {
  if ((this->size() < other.size()) || (this->size() == other.size())) {
    return true;
  } else {
    return false;
  }
};


/**
 * @brief Sobrecarga operador <<
 * 
 * @param os 
 * @param chain 
 * @return std::ostream& 
 */
std::ostream& operator<< (std::ostream& os, const Chain chain) {
  os << chain.print();
  return os;
}

/**
 * @brief Sobrecarga operador ==
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool Chain::operator== (const Chain& other) const {
  if (this->size() != other.size()) {
    return false;
  }
  
  for (auto i = 0; i < this->size(); ++i) {
    if (other.chain_[i] != this->chain_[i]) {
      return false;
    }
  }

  return true;
}

