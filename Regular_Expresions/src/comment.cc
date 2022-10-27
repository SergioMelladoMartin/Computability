#include "../lib/comment.h"

/**
 * @brief Construct a new Comment:: Comment object
 * 
 * @param value 
 * @param line 
 * @param is_decription 
 */
Comment::Comment(std::string value, int line, bool is_decription) {
  this->value_ = value;
  this->line_ = line;
  this->is_description_ = is_decription;
}

/**
 * @brief return value
 * 
 * @return std::string 
 */
std::string Comment::get_value() {
  return this->value_;
}

/**
 * @brief Return the line
 * 
 * @return int 
 */
int Comment::get_line() {
  return this->line_;
}

/**
 * @brief Return if he comment is description
 * 
 * @return true 
 * @return false 
 */
bool Comment::is_description() {
  return this->is_description_;
}
