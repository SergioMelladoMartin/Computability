//Universidad de La Laguna
//Escuela Superior de Ingeniería y Tecnología
//Grado en Ingeniería Informática
//Asignatura: Computabilidad y Algoritmia
//Curso: 2o
//Práctica 2: Operaciones con lenguajes
//Autor: Sergio Mellado Martín
//Correo: alu0101326351@ull.edu.es
//Fecha: 08/10/2022
//Archivo: alphabet.h
//         Declaración de la clase alphabet.

#pragma once 

#include <iostream>
#include <set>
#include <string>

#include "../lib/symbol.h"


class Alphabet {
  public: 
    Alphabet(std::set<Symbol>);
    Alphabet();

    int size();
    std::set<Symbol> get_alphabet() const;
    bool contains(Symbol);
    void insert_symbol(Symbol);
    std::string print() const;

    Alphabet operator+ (const Alphabet&);
    friend std::ostream& operator<< (std::ostream&, const Alphabet);

  private:
    std::set<Symbol> alphabet_;
    int size_;
};