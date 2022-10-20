#include <fstream>
#include <iostream>
#include "../lib/languaje.h"
#include "../lib/RPN.h"


/**
 * @brief Lee un lenguaje de un fichero
 * 
 * @param file 
 * @return Languaje 
 */
Languaje read_languaje(std::string line) {
  std::vector<std::string> splited_line = split(line, SEPARATOR);

  Alphabet alphabet;
  bool is_alphabet_end = false;
  bool is_chain_end = false;
  int i = 3;

  while (!is_alphabet_end) {
    alphabet.insert_symbol(Symbol(splited_line[i]));
    if (splited_line[i + 1] == "}{") {
      is_alphabet_end = true;
    }
    ++i;
  }
  ++i;

  Languaje languaje(alphabet);
  while(!is_chain_end) {
    std::string word = splited_line[i];
    Chain chain(alphabet);
    for (auto j = 0; j < word.size(); ++j) {
      std::string x;
      x.push_back(word[j]);
      Symbol symbol(x);
      chain.insert(symbol);
    }
    languaje.insert_chain(chain);

    if (splited_line[i + 1] == "}") {
      is_chain_end = true;
    }
        
    ++i;
  }

  return languaje;
}

/**
 * @brief Manejo de errores
 * 
 * @param code 
 */
void error(int code) {
  std::cout << "===SE HA PRODUCIDO UN ERROR===\n\n";
  switch(code) {
    case 1:
      std::cout << "No se han pasado los parámetros correctos. \n";
      std::cout << "Modo de ejecución => ./main [fichero input] [fichero output] \n";
      break;

    case 2: 
      std::cout << "No está definido la operación para ese opcode\n";
      std::cout << "[1]. Inversa del lenguaje\n";
      std::cout << "[2]. Potencia del lenguaje\n";
      std::cout << "[3]. Concatenación de lenguajes\n";
      std::cout << "[4]. Unión de lenguajes\n";
      std::cout << "[5]. Intersección de lenguajes\n";
      std::cout << "[6]. Resta de lenguajes\n";
      break;

    case 3:
      std::cout << "Debes pasar como argumento otro fichero con el segundo lenguaje. \n";
      std::cout << "Modo de ejecución => ./main [fichero input] [fichero output]\n";
      break;
  }

  exit(1);
}

void check(int argc, char* argv[]) {
  if (argc != 3) {
    error(1);
  }
}
