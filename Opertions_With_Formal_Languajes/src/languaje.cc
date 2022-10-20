//Universidad de La Laguna
//Escuela Superior de Ingeniería y Tecnología
//Grado en Ingeniería Informática
//Asignatura: Computabilidad y Algoritmia
//Curso: 2o
//Práctica 2: Operaciones con lenguajes
//Autor: Sergio Mellado Martín
//Correo: alu0101326351@ull.edu.es
//Fecha: 12/10/2021
//Archivo: languaje.cc
//         Implementación de los métodos de la clase languaje.

#include "../lib/languaje.h"

/** 
 * @brief Construct a new Languaje:: Languaje object
 * 
 * @param languaje 
 * @param alphabet 
 */
Languaje::Languaje(std::set<Chain> languaje, Alphabet alphabet) {
  this->languaje_ = languaje;
  this->size_ = languaje_.size();
  this->alphabet_ = alphabet;
}

/**
 * @brief Construct a new Languaje:: Languaje object
 * 
 */
Languaje::Languaje(Alphabet alphabet) {
  std::set<Chain> empty_languaje;
  this->languaje_ = empty_languaje;
  this->size_ = 0;
  this->alphabet_ = alphabet;
}

/**
 * @brief Devuelve el número de cadenas del lenguaje
 * 
 * @return int 
 */
int Languaje::size() {
  return this->size_;
}

/**
 * @brief Devuelve true si la cadena pertenece al lenguaje y false en caso contrario
 * 
 * @param symbol 
 * @return true 
 * @return false 
 */
bool Languaje::contains(Chain chain) {
  for (auto it = this->languaje_.begin(); it != this->languaje_.end(); ++it) {
    if (*it == chain) 
      return true;
    }
  return false;
}

/**
 * @brief Añade una cadena al lenguaje
 * 
 * @param new_chain 
 */
void Languaje::insert_chain(Chain new_chain) {
  if (!this->contains(new_chain)) {
    this->languaje_.insert(new_chain);
    this->size_++;
  } 
}

/**
 * @brief Imprime el lenguaje
 * 
 */
std::string Languaje::print() const{
  std::string result = "{ "; 
  for (auto it = this->languaje_.begin(); it != this->languaje_.end(); ++it) {
    result += it->print() + ", ";
  }
  result += "} Alfabeto: " + this->alphabet_.print();
  return result;
}

/**
 * @brief Devuelve el lenguaje inverso
 * 
 * @return Languaje 
 */
Languaje Languaje::operator!() {
  Languaje reverse(this->alphabet_);
  for (auto it = this->languaje_.begin(); it != this->languaje_.end(); ++it) {
    reverse.insert_chain(it->reverse()); 
  }
  return reverse;
}

/**
 * @brief Concatenación de lenguajes
 * 
 * @param other 
 * @return Languaje 
 */
Languaje Languaje::operator+(Languaje other) {
  Languaje concat(this->alphabet_ + other.alphabet_);
  for (auto i = this->languaje_.begin(); i != this->languaje_.end(); ++i) {
    for (auto j = other.languaje_.begin(); j != other.languaje_.end(); ++j) {
      concat.insert_chain(i->concat(*j));
    }
  }
  return concat;
}

/**
 * @brief Interseccion de lenguajes
 * 
 * @param other 
 * @return Languaje 
 */
Languaje Languaje::operator^(Languaje other) {
  Languaje intersection(this->alphabet_ + other.alphabet_);
  for (auto i = this->languaje_.begin(); i != this->languaje_.end(); ++i) {
    for (auto j = other.languaje_.begin(); j != other.languaje_.end(); ++j) {
      if (*i == *j) {
        intersection.insert_chain(*i);
      }
    }
  }

  if (intersection.languaje_.size() == 0) {
    Chain empty_chain({EMPTY_SYMBOL}, this->alphabet_);
    intersection.insert_chain(empty_chain);
  }

  return intersection;
}

/**
 * @brief Diferencia de lenguajes
 * 
 * @param other 
 * @return Languaje 
 */
Languaje Languaje::operator-(Languaje other) {
  Languaje minus(this->alphabet_);
  for (auto i = other.languaje_.begin(); i != other.languaje_.end(); ++i) {
    if (!this->contains(*i)) {
      minus.insert_chain(*i);
    }
  }
  return minus;
}

/**
 * @brief Potencia de lenguajes
 * 
 * @param n 
 * @return Languaje 
 */
Languaje Languaje::operator*(int n) {
  Languaje power(this->alphabet_);
  if (n == 0) {
    Chain empty_chain({EMPTY_SYMBOL}, this->alphabet_);
    power.insert_chain(empty_chain);
  } else  {
    power = *this;
    while(n >  1) {
      power = power + power;
      --n;
    }
  }

  return power;
}

/**
 * @brief Unión de lenguajes
 * 
 * @param other 
 * @return Languaje 
 */
Languaje Languaje::operator|(Languaje other) {
  Languaje u_nion(this->languaje_, this->alphabet_ + other.alphabet_);
  for (auto i = other.languaje_.begin(); i != other.languaje_.end(); ++i) {
    u_nion.insert_chain(*i);
  }
  return u_nion;
}

/**
 * @brief Sobrecarga operador <<
 * 
 * @param os 
 * @param chain 
 * @return std::ostream& 
 */
std::ostream& operator<< (std::ostream& os, const Languaje languaje) {
  os << languaje.print();
  return os;
}