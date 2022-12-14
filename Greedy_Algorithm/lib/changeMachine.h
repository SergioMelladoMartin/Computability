#include <vector>
#include <tuple>
#include <iostream>

#include "../lib/coin.h"

/**
 * @brief Class that represents a change machine
 * 
 */
class ChangeMachine {
  public:
		ChangeMachine();

		std::vector<Coin> getChange(float, int);
		std::vector<Coin> getChangeEfficient(float, int);

	private:
		std::vector<Coin> coins;
};