#include "../lib/changeMachine.h"

/**
 * @brief Construct a new Change Machine:: Change Machine object
 * 
 */
ChangeMachine::ChangeMachine() {
  std::vector<int> coinValues = {1, 2, 5, 10, 20, 50, 100, 200};

  for (auto i = 0; i < coinValues.size(); i++) {
    coins.push_back(Coin(coinValues[i]));
  }
}

/**
 * @brief Get the Change with the efficient algorithm
 * 
 * @param amount 
 * @param mode 
 * @return std::vector<Coin> 
 */
std::vector<Coin> ChangeMachine::getChangeEfficient(float amount, int mode) {
  std::cout << "Excuting the efficient algorithm O(m)...\n";
  if (mode == 1) {
    std::vector<int> coinVaues = {500, 1000, 2000, 5000, 10000, 20000, 50000};

    for (auto i = 0; i < coinVaues.size(); i++) {
      this->coins.push_back(Coin(coinVaues[i]));
    }
  }
  std::vector<Coin> result;
  int amountInCents = amount * 100;
  int sum = 0;
  for (auto i = this->coins.size() - 1; i >= 0; i--) {
    int c = (amountInCents - sum) / this->coins[i].getValue();
    if (c > 0) {
      for (auto j = 0; j < c; j++) {
        result.push_back(Coin(this->coins[i].getValue()));
      }
      sum += c * this->coins[i].getValue();
    }

    if (sum == amountInCents) {
      break;
    }
  }

  return result;
}

/**
 * @brief Get the Change with the non efficient algorithm
 * 
 * @param amount 
 * @param mode 
 * @return std::vector<Coin> 
 */
std::vector<Coin> ChangeMachine::getChange(float amount, int mode) {
  std::cout << "Excuting the non efficient algorithm O(m)...\n";
  if (mode == 1) {
    std::vector<int> coinVaues = {500, 1000, 2000, 5000, 10000, 20000, 50000};

    for (auto i = 0; i < coinVaues.size(); i++) {
      this->coins.push_back(Coin(coinVaues[i]));
    }
  }

  std::vector<Coin> result;
  int amountInCents = amount * 100;
  int sum = 0;
  while (sum != amountInCents) {
    int v = 0;
    for (auto i = 0; i < this->coins.size(); i++) {
      if ((sum + this->coins[i].getValue()) <= amountInCents) {
        v = this->coins[i].getValue();
      }
    }

    if (v == 0) {
      std::cout << "No existe solución\n";
      exit(1);
    }

    result.push_back(Coin(v));
    sum += v;
  }

  return result;
}
