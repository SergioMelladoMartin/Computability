/**
 * @brief Check input
 * 
 * @param argc 
 * @param argv 
 */
void checkInput(int argc, char** argv) {
  if ((argc < 2) || (argc > 5)) {
    std::cout << "Usage: ./changeMachine <amount> <tickets?> <output mode? <algortihm?> \n";
    exit(1);
  }

  if (std::stof(argv[1]) < 0) {
    std::cout << "Amount must be greater than 0\n";
    exit(1);
  }
}

/**
 * @brief Print results
 * 
 * @param coins 
 * @return std::string 
 */
std::string printResults(std::vector<Coin> coins) {
  std::string result = "Solution Set = { ";
  for (auto i = 0; i < coins.size(); i++) {
    float value = float(coins[i].getValue()) / 100;
    result += std::to_string(value);
    result.erase(result.end() - 4, result.end());
    result += "€ ";
  }
  result += "}\n";
  result += "Coins number = " + std::to_string(coins.size()) + "\n";
  return result;
}

/**
 * @brief Print results formatted
 * 
 * @param coins 
 * @return std::string 
 */
std::string printResultsFormatted(std::vector<Coin> coins) {
  std::string result = "Solution Set = { ";
  for (auto i = 0; i < coins.size(); i++) {
    int n = 1;
    float value = float(coins[i].getValue()) / 100;
    while ((i < coins.size()) && (value * 100 == float(coins[i + 1].getValue()))) {
      n++;
      i++;
    }
    result += std::to_string(value);
    result.erase(result.end() - 4, result.end());
    result += "€ x " + std::to_string(n) + "  ";
  }
  result += "}\nCoins Number = " + std::to_string(coins.size()) + "\n";
  return result;
}