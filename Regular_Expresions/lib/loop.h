#include <string>

class Loop {
  public:
    Loop(std::string, int);

    std::string get_type();
    int get_line();

  private:
    std::string type_;
    int line_;    
};