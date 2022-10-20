//Universidad de La Laguna
//Escuela Superior de Ingeniería y Tecnología
//Grado en Ingeniería Informática
//Asignatura: Computabilidad y Algoritmia
//Curso: 2o
//Práctica 2: Operaciones con lenguajes
//Autor: Sergio Mellado Martín
//Correo: alu0101326351@ull.edu.es
//Fecha: 08/10/2022
//Archivo: languaje.h
//         Declaración de la clase languaje.

#pragma once 

#include <iostream>
#include <set>
#include <string>

#include "../lib/alphabet.h"
#include "../lib/chain.h"

class Languaje {
  public: 
    Languaje(std::set<Chain>, Alphabet);
    Languaje(Alphabet);

    int size();
    bool contains(Chain);
    void insert_chain(Chain);
    std::string print() const;

    Languaje operator!();
    Languaje operator+(Languaje);
    Languaje operator|(Languaje);
    Languaje operator^(Languaje);
    Languaje operator*(int);
    Languaje operator-(Languaje);

    friend std::ostream& operator<< (std::ostream&, const Languaje);

  private:
    std::set<Chain> languaje_;;
    Alphabet alphabet_;
    int size_;
};