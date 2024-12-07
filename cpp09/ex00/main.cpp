#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <string>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./btc [filename]" << std::endl;
    return 1;
  }
  (void)argv;
  BitcoinExchange btc;
  std::ifstream input;

  input.open(argv[1]);
  std::string line;
  std::string inputStr;
  std::getline(input, line);
  while (std::getline(input, line)) {

    inputStr += line;
    inputStr += "\n";
  }

  try {
    btc.process(inputStr);
  } catch (std::exception w) {
    std::cout << "error:" << w.what() << std::endl;
  }
}