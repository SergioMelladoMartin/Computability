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
//         Declaración de la clase chain.
#pragma once

#include <vector>

#include "../lib/symbol.h"
#include "../lib/alphabet.h"

const Symbol EMPTY_SYMBOL("&");

class Chain {
  public:
    Chain(std::vector<Symbol>, Alphabet);
    Chain(Alphabet);

    void insert(Symbol);

    int size() const;
    std::vector<Symbol> getChain() const;
    Alphabet get_alphabet();
    std::string print() const;
    Chain reverse() const;
    std::vector<Chain> prefix();
    std::vector<Chain> sufix();
    std::vector<Chain> subchains();

    Chain concat(Chain) const;

    Symbol operator[](int);
    bool operator< (const Chain&) const;
    friend std::ostream& operator<< (std::ostream&, const Chain);
    bool operator== (const Chain&) const;

  private:
    std::vector<Symbol> chain_;
    Alphabet alphabet_;
    int size_;
};