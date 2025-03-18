#include "PmergeMe.hpp"
#include <algorithm>
#include <utility>
#include <vector>

#include <string>

#include <iostream>
#include <string>

static int stringToInt(std::string str) {
    int                result = 0;
    unsigned long long i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
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

PmergeMe::PmergeMe(char **input) { parseInput(input); }

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

static double currentUsTime() {
    clock_t start_vector = clock();
    return (double)start_vector / CLOCKS_PER_SEC;
}

void PmergeMe::processData() {

    std::cout << "Vector Before :" << std::endl;
    double start = currentUsTime();
    printContainer(_vectorData);
    _vectorData = fordJhonson(_vectorData, 0);
    double end = currentUsTime();
    std::cout << "Vector After :" << std::endl;
    printContainer(_vectorData);
    double vectorTime = end - start;

    std::cout << "Deque Before :" << std::endl;
    start = currentUsTime();
    printContainer(_dequeData);
    _dequeData = fordJhonson(_dequeData, 0);
    end = currentUsTime();
    std::cout << "Deque After :" << std::endl;
    printContainer(_dequeData);
    std::cout << "\n\nVector Time: " << vectorTime << "ms" << std::endl;
    std::cout << "std::vector time to process " << _vectorData.size()
              << " elements : " << (vectorTime) * 1000000 << " us" << std::endl;
    std::cout << "std::deque time to process " << _dequeData.size()
              << " elements : " << (end - start) * 1000000 << " us" << std::endl;

    _dequeData = fordJhonson(_dequeData, 0);
}
