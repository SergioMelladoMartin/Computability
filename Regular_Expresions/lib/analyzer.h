#include <string>
#include <regex>
#include <iostream>
#include <fstream>

#include "../lib/variable.h"
#include "../lib/loop.h"
#include "../lib/comment.h"

class Analyzer {
  public:
    Analyzer();

    std::string analyze(std::string);
  
  private:
    std::string name_;
    bool has_main_;
    std::vector<Variable> variables_;
    std::vector<Loop> loops_;
    std::vector<Comment> comments_;

    std::string print_name();
    std::string print_description();
    std::string print_variables();
    std::string print_loops();  
    std::string print_main();
    std::string print_comments();

};