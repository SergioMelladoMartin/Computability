//Universidad de La Laguna
//Escuela Superior de Ingeniería y Tecnología
//Grado en Ingeniería Informática
//Asignatura: Computabilidad y Algoritmia
//Curso: 2o
//Práctica 2: Símbolos, cadenas y alfabetos
//Autor: Sergio Mellado Martín
//Correo: alu0101326351@ull.edu.es
//Fecha: 12/10/2021
//Archivo: alphabet.cc
//         Implementación de los métodos de la clase alphabet.

#include "../lib/alphabet.h"

/**
 * @brief Construct a new Alphabet:: Alphabet object
 * 
 * @param alphabet 
 */
Alphabet::Alphabet(std::set<Symbol> alphabet) {
  this->alphabet_ = alphabet;
  this->size_ = alphabet_.size();
}

/**
 * @brief Construct a new Alphabet:: Alphabet object
 * 
 */
Alphabet::Alphabet() {
  std::set<Symbol> empty_alphabet;
  this->alphabet_ = empty_alphabet;
  this->size_ = 0;
}

/**
 * @brief Devuelve el tamaño de alfabeto
 * 
 * @return int 
 */
int Alphabet::size() {
  return this->size_;
}

/**
 * @brief Devuelve el alfabeto
 * 
 * @return std::set<Symbol> 
 */
std::set<Symbol> Alphabet::get_alphabet() const{
  return this->alphabet_;
}

/**
 * @brief Devuelve true si el alfabeto contiene el simbolo, false si no
 * 
 * @param symbol 
 * @return true 
 * @return false 
 */
bool Alphabet::contains(Symbol symbol) {
  for (auto it = this->alphabet_.begin(); it != this->alphabet_.end(); ++it) {
    if (*it == symbol) 
      return true;
  
  }
  return false;
}

/**
 * @brief Inserta un símbolo al alfabeto
 * 
 * @param new_symbol 
 */
void Alphabet::insert_symbol(Symbol new_symbol) {
  if (!this->contains(new_symbol)) {
    this->alphabet_.insert(new_symbol);
  }
}

/**
 * @brief Imprime el alfabeto
 * 
 */
std::string Alphabet::print() const{
  std::string result = "{ "; 
  for (auto it = this->alphabet_.begin(); it != this->alphabet_.end(); ++it) {
    result += it->get_symbol() + ' ';
  }
  result += "}\n";
  return result;
}


Alphabet Alphabet::operator+ (const Alphabet& other) {
  Alphabet alphabet(this->get_alphabet());

  std::set<Symbol> other_alphabet = other.get_alphabet();
  for (auto it = other_alphabet.begin(); it != other_alphabet.end(); ++it) {
    alphabet.insert_symbol(*it);
  }
  return alphabet;
};

/**
 * @brief Sobrecarga operador <<
 * 
 * @param os 
 * @param chain 
 * @return std::ostream& 
 */
std::ostream& operator<< (std::ostream& os, const Alphabet alphabet) {
  os << alphabet.print();
  return os;
}
