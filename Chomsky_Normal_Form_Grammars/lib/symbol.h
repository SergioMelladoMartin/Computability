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
//         Declaración de la clase symbol.

#pragma once 

#include <string>
#include <iostream> 

class Symbol {
  public:
    Symbol(std::string);
    Symbol();
    std::string get_symbol() const;
    void set_symbol(std::string);

    bool operator< (const Symbol& other) const;
    bool operator== (const Symbol& other) const;
    bool operator!= (const Symbol& other) const;
    friend std::ostream& operator<< (std::ostream&, const Symbol);

  private:
    std::string symbol_;
};