#include <string>

class Comment {
  public:
    Comment(std::string, int, bool);

    std::string get_value();
    int get_line();
    bool is_description();

  private:  
    std::string value_;
    int line_;
    bool is_description_;
};