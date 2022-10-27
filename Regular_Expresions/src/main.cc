#include <iostream>
#include <fstream>

#include "../lib/analyzer.h"

/**
 * @brief Check if the number of params is correct
 * 
 * @param argc 
 */
void check(int argc) {
  if (argc != 3) {
    std::cout << "ERROR!!\n";
    std::cout << "Execution mode: ./main [file.cpp] [output.txt]\n";
    exit(1);
  }
}

/**
 * @brief Main function
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[]) {
  check(argc);
  std::ofstream output_file(argv[2]);

  Analyzer analyzer;
  output_file << analyzer.analyze(argv[1]);
}