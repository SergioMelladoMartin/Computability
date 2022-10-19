//Universidad de La Laguna
//Escuela Superior de Ingeniería y Tecnología
//Grado en Ingeniería Informática
//Asignatura: Computabilidad y Algoritmia
//Curso: 2o
//Práctica 2: Símbolos, cadenas y alfabetos
//Autor: Sergio Mellado Martín
//Correo: alu0101326351@ull.edu.es
//Fecha: 28/09/2022
//Archivo: main.cc
//         Programa principal         

#include "../lib/alphabet.h"
#include "../lib/symbol.h"
#include "../lib/chain.h"

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <fstream>

const char SEPARATOR = ' ';

/**
 * @brief Separa un string por un separador
 * 
 * @param line 
 * @param separator 
 * @return std::vector<std::string> 
 */
std::vector<std::string> split(std::string line, const char separator) {
  std::vector<std::string> line_splited;
  std::string word;

  for(auto i = 0; i < line.size(); ++i) {
    if(line[i] == separator){
      line_splited.push_back(word);
      word.clear();
    } else {
      word.push_back(line[i]);
    }
  }

  line_splited.push_back(word);
  return line_splited;
};

/**
 * @brief Manejo de errores
 * 
 * @param code 
 */
void error(int code) {
  std::cout << "===ERROR===\n\n";
  switch(code) {
    case 1:
      std::cout << "Chain can´t be formated with that symbols, please change it\n";
      break;

    case 2:
      std::cout << "Wrong number of params. \n";
      std::cout << "Excution => ./main [input file] [output file] [opcode]\n";
      break;

    case 3: 
      std::cout << "Wrong opcode\n";
      std::cout << "[1]. Chain's lenght\n";
      std::cout << "[2]. Chain's reverse\n";
      std::cout << "[3]. Chain's prefix\n";
      std::cout << "[4]. Chain's sufix\n";
      std::cout << "[5]. Chain's subchains\n";
      break;

  }

  exit(1);
}

/**
 * @brief Programa principal
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]) {
  if (argc != 4) {
    error(2);
  }

  if ((atoi(argv[3]) <= 0) || (atoi(argv[3]) > 5)) {
    error(3);
  }

  std::ifstream input_file(argv[1]);
  std::ofstream output_file(argv[2]);
  int opcode = atoi(argv[3]);
  std::string line;
  
  while(getline(input_file, line)) {
    std::vector<std::string> splited_line = split(line, SEPARATOR);

    Alphabet alphabet;

    if (splited_line.size() == 1) {
      std::string symbols = splited_line[0];
      for (auto i = 0; i < symbols.size(); ++i) {
        std::string symbol;
        symbol.push_back(symbols[i]);
        Symbol new_symbol(symbol);
        alphabet.insert_symbol(new_symbol);
      }
    } else {
      for (auto i = 0; i < splited_line.size() - 1; ++i) {
        Symbol new_symbol(splited_line[i]);
        alphabet.insert_symbol(new_symbol);
      }
    }

    std::string str = splited_line[splited_line.size() - 1];
    Chain chain(alphabet);
    for (auto i = 0; i < str.size(); ++i) {
      bool stop = false;
      std::string word = "";
      while(!stop) {
        word.push_back(str[i]);

        Symbol new_symbol(word);
        if (alphabet.contains(new_symbol)) {
          chain.insert(new_symbol);
          word = "";
          stop = true;
          break;
        }

        i++;

        if (i >= str.size())
          error(1);
      }
    }

    switch(opcode) {
      case 1: {
        output_file << chain << " Lenght => " << chain.size() << '\n';
        break;
      }

      case 2: {
        output_file << chain << " Reverse => ";
        Chain reverse = chain.reverse();
        output_file << reverse << '\n';
        break;
      }

      case 3: {
        output_file << chain << " Prefix => {";
        std::vector<Chain> prefix = chain.prefix();
        for (auto i = 0; i < prefix.size(); ++i) {
          output_file << prefix[i];
        }
        output_file << "}\n";
        break;
      }

      case 4: {
        output_file << chain << " Sufix => {";
        std::vector<Chain> sufix = chain.sufix();
        for (auto i = 0; i < sufix.size(); ++i) {
          output_file << sufix[i];
        }
        output_file << "}\n";
        break;
      }

      case 5: {
        output_file << chain << " Subchains => {";
        std::vector<Chain> subchains = chain.subchains();
        for (auto i = 0; i < subchains.size(); ++i) {
          output_file << subchains[i];
        }
        output_file << "}\n";
        break;
      }
    }
  }

  
}