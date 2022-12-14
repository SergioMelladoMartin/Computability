#include "../lib/coin.h"

/**
 * @brief Construct a new Coin:: Coin object
 * 
 * @param value 
 */
Coin::Coin(int value) {
  this->value = value;
}

/**
 * @brief Get the Value object
 * 
 * @return int 
 */
int Coin::getValue() const {
  return value;
}