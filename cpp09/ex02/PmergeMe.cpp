#include "PmergeMe.hpp"
#include <algorithm>
#include <vector>

#include <string>

#include <iostream>
#include <string>


static int stringToInt(std::string str) {
    int           result = 0;
    unsigned long long i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') // Vérification si c'est un chiffre
            throw PmergeMe::InvalidInput();
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (result != static_cast<int>(result))
		throw PmergeMe::InvalidInput();

	
    return result;
}

std::ostream &operator<<(std::ostream &os, const PmergeMe &pm) {

    std::deque<int>  deque = pm.getDequeData();
    std::vector<int> vector = pm.getVectorData();

    os << "deque: ";
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++) {
        os << *it << " ";
    }
    os << std::endl;

    os << "vector: ";
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++) {
        os << *it << " ";
    }
    os << std::endl;

    return os;
}

const char *PmergeMe::InvalidInput::what() const throw() { return "Error: Invalid input !"; }

PmergeMe::PmergeMe(char **input) {
    parseInput(input);
    // throw InvalidInput();
}

static bool isNumber(const std::string &str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void PmergeMe::parseInput(char **input) {
    for (int i = 0; input[i]; i++) {
        std::cout << input[i] << std::endl;
        if (!isNumber(input[i]))
            throw InvalidInput();
        int tmp = stringToInt(input[i]);
        _dequeData.push_back(tmp);
        _vectorData.push_back(tmp);
    }
    std::cout << *this << std::endl;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::processData() { return; }