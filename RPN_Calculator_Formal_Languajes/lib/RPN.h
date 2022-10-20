#pragma once

#include <stack>
#include <string>
#include <vector>

#include "../lib/languaje.h"

const char SEPARATOR = ' ';

class RPN {
  public:
    RPN(std::vector<Languaje>);
    Languaje operate(std::string);

  
    std::vector<Languaje> languajes_;
};

std::vector<std::string> split(std::string line, const char separator);