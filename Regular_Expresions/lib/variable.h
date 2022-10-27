#include <string>

class Variable {
  public: 
    Variable(std::string, std::string, int);
    
    std::string get_type();
    std::string get_value();
    int get_line();

  private:
    std::string type_;
    std::string value_;
    int line_;
};