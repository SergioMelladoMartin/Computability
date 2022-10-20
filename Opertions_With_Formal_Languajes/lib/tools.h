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
 * @brief Lee un lenguaje de un fichero
 * 
 * @param file 
 * @return Languaje 
 */
Languaje read_languaje(std::string file) {
  std::ifstream input_file(file);
  std::string line;
  getline(input_file, line);
  std::vector<std::string> splited_line = split(line, SEPARATOR);

  Alphabet alphabet;
  bool is_alphabet_end = false;
  bool is_chain_end = false;
  int i = 1;

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
  std::cout << "===ERROR===\n\n";
  switch(code) {
    case 1:
      std::cout << "Wrong number of arguments. \n";
      std::cout << "Execution mode => ./main [input file] [output file] [opcode] [input file 2 / exponent (If necessary)]\n";
      break;

    case 2: 
      std::cout << "Wrong opcode\n";
      std::cout << "[1]. Languaje's reverse\n";
      std::cout << "[2]. Power\n";
      std::cout << "[3]. Concatenation\n";
      std::cout << "[4]. Unión\n";
      std::cout << "[5]. Intersection\n";
      std::cout << "[6]. Substraction\n";
      break;

    case 3:
      std::cout << "You must put another file / exponent. \n";
      std::cout << "Execution mode => ./main [input file] [output file] [opcode] [input file 2 / exponent (If necessary)]\n";
      break;
  }

  exit(1);
}

void check(int argc, char* argv[]) {
  if ((argc != 4) && (argc != 5) && (argc != 6)) {
    error(1);
  }

  if ((atoi(argv[3]) <= 0) || (atoi(argv[3]) >= 7)) {
    error(2);
  }
}

bool checkIfFile(int argc) {
  if ((argc == 5) || (argc == 6)) {
    return true;
  } else {
    error(3);
    return false;
  }
}