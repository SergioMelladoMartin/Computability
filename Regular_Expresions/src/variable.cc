#include "../lib/variable.h"

/**
 * @brief Construct a new Variable:: Variable object
 * 
 * @param type 
 * @param value 
 * @param line 
 */
Variable::Variable(std::string type, std::string value, int line) {
  type_ = type;
  value_ = value;
  line_ = line;
}

/**
 * @brief Return the type of the loop
 * 
 * @return std::string 
 */
std::string Variable::get_type() {
  return type_;
}

/**
 * @brief Return the value of the loop
 * 
 * @return std::string 
 */
std::string Variable::get_value() {
  return value_;
}

/**
 * @brief Return the line
 * 
 * @return int 
 */
int Variable::get_line() {
  return line_;
}