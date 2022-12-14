#include <iostream>

#include "../lib/changeMachine.h"
#include "../lib/utils.h"

/**
 * @brief Main function
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char** argv) {
  checkInput(argc, argv);

  std::vector<bool> flags = {false, false, false};
  for (auto i = 2; i < argc; i++) {
    if (std::string(argv[i]) == "-b") {
      flags[0] = true;
    } else if (std::string(argv[i]) == "-e") {
      flags[1] = true;
    } else if (std::string(argv[i]) == "-c") {
      flags[2] = true;
    }
  }

  ChangeMachine machine;
  std::vector<Coin> coins;
  if (flags[1]) {
    coins = machine.getChangeEfficient(std::stof(argv[1]), flags[0]);
  } else {
    coins = machine.getChange(std::stof(argv[1]), flags[0]);
  }

  if (flags[2]) {
    std::cout << printResultsFormatted(coins);
  } else {
    std::cout << printResults(coins);
  }
}