
#include <iostream>
#include <map>

#define DATA_PATH "data.csv"

class BitcoinExchange {
public:
  BitcoinExchange();
  ~BitcoinExchange();
  void printLine(std::string year, std::string day, std::string month, float value);
  void process(std::string input);
  void matchDate(const std::string &input);
  class InvalidDateException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Invalid date"; }
  };
  class InvalidInputException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Invalid input"; }
  };
  class InvalidFormatException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Invalid format"; }
  };

private:
  std::map<std::string, float> _data;
};
