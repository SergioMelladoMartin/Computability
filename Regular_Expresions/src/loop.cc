#include "../lib/loop.h"

/**
 * @brief Construct a new Loop:: Loop object
 * 
 * @param type 
 * @param line 
 */
Loop::Loop(std::string type, int line) {
  type_ = type;
  line_ = line;
}

/**
 * @brief Return the type of the variable
 * 
 * @return std::string 
 */
std::string Loop::get_type() {
  return type_;
}

/**
 * @brief Return the line
 * 
 * @return int 
 */
int Loop::get_line() {
  return line_;
}
