#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <regex.h>
#define MAX_MATCHES 5

static int strtoi(const std::string &str) {
  int i;
  std::istringstream(str) >> i;
  return i;
}

static float strtof(const std::string &str) {
  float i;
  std::istringstream(str) >> i;
  return i;
}

static void split(std::string *input, char delimiter, std::string (&arr)[2]) {
  std::istringstream stream(*input);
  std::string token;
  int i = 0;
  while (getline(stream, token, delimiter))
    arr[i++] = token;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange() {
  std::ifstream dataFile;
  std::string line;

  dataFile.open(DATA_PATH);

  while (std::getline(dataFile, line)) {
    std::string splited[2];
    split(&line, ',', splited);
    _data[splited[0]] = std::atof(splited[1].c_str());
  }
}

static void dateChecks(int year, int month, int day) {
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (month < 1 || month > 12 || day < 1 || day > 31)
        throw BitcoinExchange::InvalidDateException();

    if (month == 2) {
        if (day > 29 || (day == 29 && !isLeapYear))
            throw BitcoinExchange::InvalidDateException();
    } 
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        throw BitcoinExchange::InvalidDateException();
    }
}

static void valueCheck(float value) {
    if (value < 0 || value > 1000)
        throw BitcoinExchange::InvalidInputException();
}

void BitcoinExchange::printLine(std::string year, std::string day, std::string month, float value) {
    std::string date = year + "-" + month + "-" + day;
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    float euroValue = 0;
    if (it == _data.end() || it->first != date) {
        if (it == _data.begin()) {
            throw std::runtime_error("Error: date not found.");
        }
        --it;
    }
    euroValue= it->second * value;
    std::cout << year << "-" << month << "-" << day << " => " << value << " = ";
    std::cout << euroValue << "€"<< std::endl;
}

void BitcoinExchange::matchDate(const std::string &input) {
  regex_t regex;
  regmatch_t matches[MAX_MATCHES];

  const char *pattern =
      "^([0-9]{4})-([0-9]{2})-([0-9]{2})[ ]?\\|[ ]?(-?([0-9]+)?(\\.[0-9]+)?)$";

  if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
    std::cerr << "Regex didnt compile :(\n";
    return;
  }

  // Exécution de la regex
  if (regexec(&regex, input.c_str(), MAX_MATCHES, matches, 0) == 0) {
    std::string year =
        input.substr(matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so);
    std::string month =
        input.substr(matches[2].rm_so, matches[2].rm_eo - matches[2].rm_so);
    std::string day =
        input.substr(matches[3].rm_so, matches[3].rm_eo - matches[3].rm_so);
    std::string value =
        input.substr(matches[4].rm_so, matches[4].rm_eo - matches[4].rm_so);
    regfree(&regex);
    
    dateChecks(strtoi(year), strtoi(month), strtoi(day));
    valueCheck(strtof(value));
    BitcoinExchange::printLine(year, day, month, strtof(value));
  } else
  {
      regfree(&regex);
      throw BitcoinExchange::InvalidFormatException();
  }
  // Libération de la mémoire
}

void BitcoinExchange::process(std::string input) {
  std::istringstream stream(input);
  std::string token;

  while (getline(stream, token, '\n')) {
    // std::cout << "token = " << token << std::endl;
    try {
      matchDate(token);
    } catch (std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }

}