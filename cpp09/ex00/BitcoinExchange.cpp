#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <pcre2.h>

static void split(std::string *input, char delimiter,
                 std::string (&arr)[2])
{
    std::istringstream stream(*input);
    std::string token;
    int i = 0;
    while (getline(stream, token, delimiter))
        arr[i++] = token;
}


BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(){
    std::ifstream dataFile;
    std::string line;

    dataFile.open(DATA_PATH);

    while(std::getline(dataFile, line))
    {
        std::string splited[2];
        split(&line, ',', splited);
        _data[splited[0]] = std::atof(splited[1].c_str());
        std::cout  <<splited[1]<< std::endl;
        std::cout  <<_data[splited[0]]   << std::endl;
    }

}

void BitcoinExchange::process(std::string input)
{
    std::cout <<  input << std::endl;
}