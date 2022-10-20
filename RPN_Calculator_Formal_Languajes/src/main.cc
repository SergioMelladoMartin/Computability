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

#include "../lib/alphabet.h"
#include "../lib/symbol.h"
#include "../lib/chain.h"
#include "../lib/languaje.h"
#include "../lib/RPN.h"
#include "../lib/tools.h"

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <fstream>

int main(int argc, char* argv[]) {
  check(argc, argv);
  std::ifstream input_file(argv[1]);
  std::ofstream output_file(argv[2]);

  std::vector<Languaje> languajes;
  std::vector<std::string> operations;

  std::string line;
  while(getline(input_file, line)) {
    if (line[0] == 'L') {
      Languaje languaje = read_languaje(line);
      languajes.push_back(languaje);
    } else {
      operations.push_back(line);
    }
  };

  RPN rpn(languajes);

  for (auto i = 0; i < operations.size(); ++i) {
    Languaje result = rpn.operate(operations[i]);
    output_file << result;
  }
}