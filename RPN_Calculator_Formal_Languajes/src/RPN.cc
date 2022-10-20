#include "../lib/RPN.h"

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
 * @brief Construct a new RPN::RPN object
 * 
 * @param languajes 
 */
RPN::RPN(std::vector<Languaje> languajes) {
  languajes_ = languajes;
}

/**
 * @brief Ejecuta la caluladora
 * 
 * @param expresion 
 * @return Languaje 
 */
Languaje RPN::operate(std::string expresion) {
  std::vector<std::string> operations = split(expresion, SEPARATOR);
  std::stack<Languaje> stack_operation;
  
  while (operations.size() != 0) {
    std::string next = operations[operations.size() - 1];
    operations.pop_back();

    if ((next != "+") && (next != "-") && (next != "*") && (next != "!") && (next != "|") && (next != "^")) {
      next.erase(0, 1);
      stack_operation.push(languajes_[stoi(next) - 1]);
    } else {
      if (next == "+") {
        if (stack_operation.size() < 2) {
          std::cout << "ERROR: The operation can't be calculated. Wrong number of arguments\n";
          exit(0);
        }

        Languaje op1 = stack_operation.top();
        stack_operation.pop();

        Languaje op2 = stack_operation.top();
        stack_operation.pop();

        stack_operation.push(op1 + op2);
      }

      if (next == "|") {
        if (stack_operation.size() < 2) {
          std::cout << "ERROR: The operation can't be calculated. Wrong number of arguments\n";
          exit(0);
        }

        Languaje op1 = stack_operation.top();
        stack_operation.pop();

        Languaje op2 = stack_operation.top();
        stack_operation.pop();

        stack_operation.push(op1 | op2);
      }

      if (next == "^") {
        if (stack_operation.size() < 2) {
          std::cout << "ERROR: The operation can't be calculated. Wrong number of arguments\n";
          exit(1);
        }

        Languaje op1 = stack_operation.top();
        stack_operation.pop();

        Languaje op2 = stack_operation.top();
        stack_operation.pop();

        stack_operation.push(op1 ^ op2);
      }

      if (next == "-") {
        if (stack_operation.size() < 2) {
          std::cout << "ERROR: The operation can't be calculated. Wrong number of arguments\n";
          exit(1);
        }

        Languaje op1 = stack_operation.top();
        stack_operation.pop();

        Languaje op2 = stack_operation.top();
        stack_operation.pop();

        stack_operation.push(op1 - op2);
      }

      if (next == "!") {
        if (stack_operation.size() < 1) {
          std::cout << "ERROR: The operation can't be calculated. Wrong number of arguments\n";
          exit(1);
        }

        Languaje op1 = stack_operation.top();
        stack_operation.pop();

        stack_operation.push(!op1);
      }
    }
  }

  if (stack_operation.size() == 1) {
    return stack_operation.top();
  } else {
    std::cout << "ERROR: The operation can't be calculated. Wrong number of arguments\n";
    exit(0);
  }
}