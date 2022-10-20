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
#include "../lib/tools.h"

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <fstream>

int main(int argc, char* argv[]) {
  check(argc, argv);
  Languaje languaje = read_languaje(argv[1]);
  std::ofstream output_file(argv[2]);
  int opcode = atoi(argv[3]);

  switch (opcode) {
    case 1: {
      output_file << "Reverse L1 ^-1 = " << !languaje;
      break;
    }

    case 2: {
      if (checkIfFile(argc)) {
        int pow = atoi(argv[4]);
        output_file << "Power L1 ^ " << pow << " = " << languaje * pow;
      }
      break;
    }

    case 3: {
      if (checkIfFile(argc)) {
        Languaje other = read_languaje(argv[4]);
        output_file << "Concatenation L1 + L2 = " << languaje + other;
      }
      break;
    }

    case 4: {
      if (checkIfFile(argc)) {
        Languaje other = read_languaje(argv[4]);
        output_file << "Union L1 U L2 = " << (languaje | other);
      }
      break;
    }

    case 5: {
      if (checkIfFile(argc)) {
        Languaje other = read_languaje(argv[4]);
        output_file << "Intersection L1 ^ L2 = " << (languaje ^ other);
      }
      break;
    }

    case 6: {
      if (checkIfFile(argc)) {
        Languaje other = read_languaje(argv[4]);
        output_file << "Substraction L1 - L2 = " << languaje - other;
      }
      break;
    }
  }
}