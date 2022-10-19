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
  this->alphabet_.insert(new_symbol);
}

/**
 * @brief Imprime el alfabeto
 * 
 */
void Alphabet::print() {
  std::cout << "{ "; 
  for (auto it = this->alphabet_.begin(); it != this->alphabet_.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << "}\n";
}