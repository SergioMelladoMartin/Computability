//Universidad de La Laguna
//Escuela Superior de Ingeniería y Tecnología
//Grado en Ingeniería Informática
//Asignatura: Computabilidad y Algoritmia
//Curso: 2o
//Práctica 2: Símbolos, cadenas y alfabetos
//Autor: Sergio Mellado Martín
//Correo: alu0101326351@ull.edu.es
//Fecha: 28/09/2022
//Archivo: symbol.h
//         Implementación de los métodos de la clase symbol

#include "../lib/symbol.h"

/**
 * @brief Construct a new Symbol:: Symbol object
 * 
 * @param symbol 
 */
Symbol::Symbol(std::string symbol) {
  this->set_symbol(symbol);
}

/**
 * @brief Guarda el símbolo
 * 
 * @param symbol 
 */
void Symbol::set_symbol(std::string symbol) {
  this->symbol_ = symbol;
}

/**
 * @brief DEvuelve el símbolo en formato string
 * 
 * @return std::string 
 */
std::string Symbol::get_symbol() const{
    return this->symbol_;
}

/**
 * @brief SObrecarga de operador <
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool Symbol::operator< (const Symbol& other) const{
  if (this->get_symbol() < other.get_symbol())
    return true;
  else
    return false;
}

/**
 * @brief Sobrecarga de operador ==
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool Symbol::operator== (const Symbol& other) const{
  if (this->get_symbol() == other.get_symbol())
    return true;
  else
    return false;
}

/**
 * @brief Sobrecarga operador <<
 * 
 * @param os 
 * @param my_symbol 
 * @return std::ostream& 
 */
std::ostream& operator<< (std::ostream& os, const Symbol my_symbol) {
  os << my_symbol.get_symbol();
  return os;
}
