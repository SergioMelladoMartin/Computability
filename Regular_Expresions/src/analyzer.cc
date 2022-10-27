#include "../lib/analyzer.h"

/**
 * @brief Construct a new Analyzer:: Analyzer object
 * 
 */
Analyzer::Analyzer() {

}

/**
 * @brief analyze the code
 * 
 * @param file 
 * @return std::string 
 */
std::string Analyzer::analyze(std::string file) {
  this->name_ = file;
  std::ifstream input_file(file); 

  std::regex expression_variable("\\S*(int|double)\\s[A-Za-z]*(\\s=\\s(\\d|\\d\\.\\d|[A-Za-z]);|;)$");
  std::regex expression_loop("\\s*(for|while)\\s*[(]\\s*");
  std::regex expression_comments("(((^|\\s)/\\*)|((^|\\s)\\*\\s.*)|(\\*/$))|((^|\\s)//.*)");
  std::regex expression_main("\\s*(int|void)\\s+main\\s*[(]");

  std::smatch matches_variable;
  std::smatch matches_loop; 
  std::smatch matches_comments;
  std::smatch matches_main;

  std::string line;
  int number_of_line = 1;

  while(getline(input_file, line)) {

    if (std::regex_search(line, matches_variable, expression_variable)) {
      this->variables_.push_back(Variable(matches_variable[1], matches_variable[0], number_of_line));
    }

    if (std::regex_search(line, matches_loop, expression_loop)) {
      this->loops_.push_back(Loop(matches_loop[1], number_of_line));
    }

    if (std::regex_search(line, matches_main, expression_main)) {
      this->has_main_ = true;
    }

    if (std::regex_search(line, matches_comments, expression_comments)) {
      if (number_of_line == 1) {
        bool end_of_description = false;
        std::string value = line;
        while (end_of_description == false) {
          getline(input_file, line);
          number_of_line++;
          if (line != "*/") {
            value += line + '\n';
          } else {
            value += line;
            end_of_description = true;
          }
        }
        this->comments_.push_back(Comment(value, number_of_line, true));
      } else {
        this->comments_.push_back(Comment(matches_comments[0], number_of_line, false));
      }
    }

    number_of_line++;
  }

  std::string output = 
      this->print_name()
    + this->print_description()
    + this->print_variables() 
    + this->print_loops() 
    + this->print_main()
    + this->print_comments();


  return output;
}

/**
 * @brief Print name of file
 * 
 * @return std::string 
 */
std::string Analyzer::print_name() {
  return "Name: " + this->name_ + "\n";
}

/**
 * @brief Print description
 * 
 * @return std::string 
 */
std::string Analyzer::print_description() {
  std::string out = "DESCRIPTION:\n";
  for (int i = 0; i < this->comments_.size(); i++) {
    if (this->comments_[i].is_description()) {
      out += this->comments_[i].get_value() + '\n';
      break;
    }
  }
  return out;
}

/**
 * @brief Print variables
 * 
 * @return std::string 
 */
std::string Analyzer::print_variables() {
  std::string out;
  out += "\nVARIABLES:\n";
  for (int i = 0; i < variables_.size(); i++) {
    out +="[Line " + std::to_string(variables_[i].get_line()) + "] ";
    if (variables_[i].get_type() == "int") {
      out += "INT: ";
      out += variables_[i].get_value().erase(0, 4) + "\n";
    } else {
      out += "DOUBLE: ";
      out += variables_[i].get_value().erase(0, 7) + "\n";
    }
  }

  return out;
}

/**
 * @brief Print loops
 * 
 * @return std::string 
 */
std::string Analyzer::print_loops() {
  std::string out;
  out += "\nLOOPS:\n";
  for (int i = 0; i < loops_.size(); i++) {
    out +="[Line " + std::to_string(loops_[i].get_line()) + "] ";
    if (loops_[i].get_type() == "for") {
      out += "LOOP: for\n";
    } else {
      out += "LOOP: while\n";
    }
  }

  return out;
}

/**
 * @brief Print comments
 * 
 * @return std::string 
 */
std::string Analyzer::print_comments() {
  std::string out;
  out += "\nCOMMENTS:\n";
  for (int i = 0; i < comments_.size(); i++) {
    if (!comments_[i].is_description()) {
      out +="[Line " + std::to_string(comments_[i].get_line()) + "]: ";
      out += comments_[i].get_value() + "\n";
    } else {
      out += "[Line 1 - " + std::to_string(comments_[i].get_line()) + "]: DESCRIPTION\n";
    }
  }

  return out;
}

/**
 * @brief Print if has main or not
 * 
 * @return std::string 
 */
std::string Analyzer::print_main() {
  std::string out;
  out += "\nMAIN:\n";
  if (this->has_main_) {
    out += "true\n";
  } else {
    out += "false\n";
  }

  return out;
}

