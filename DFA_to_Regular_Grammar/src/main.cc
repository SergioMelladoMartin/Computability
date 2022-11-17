//Universidad de La Laguna
//Escuela Superior de Ingeniería y Tecnología
//Grado en Ingeniería Informática
//Asignatura: Computabilidad y Algoritmia
//Curso: 2o
//Práctica 2: Operaciones con lenguajes.
//Autor: Sergio Mellado Martín
//Correo: alu0101326351@ull.edu.es
//Fecha: 28/09/2022
//Archivo: main.cc
//         Programa principal         

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <fstream>

#include "../lib/tools.h"
#include "../lib/NFA.h"
#include "../lib/grammar.h"

/**
 * @brief Main function
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Usage: ./main <file> <chains>" << std::endl;
    return 1;
  }

  NFA nfa = readNFA(argv[1]);
 
  Grammar grammar = nfa.toGrammar();

  std::ofstream output_file(argv[2]);
  output_file << grammar.printFormated() << "\n";
}