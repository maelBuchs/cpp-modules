#pragma once

#include <deque>
#include <exception>
#include <ostream>
#include <iostream>
#include <string>
#include <vector>

typedef std::pair<int, int> intPair;
typedef std::vector<intPair> pairVec;


class PmergeMe {
  public:
    PmergeMe(char **input);
    ~PmergeMe();

    std::deque<int>  getDequeData() const { return _dequeData; }
    std::vector<int> getVectorData() const { return _vectorData; }

    class InvalidInput : public std::exception {
      public:
        const char *what() const throw();
    };
    void processData();

  private:
    void parseInput(char **input);
    std::vector<int> vectorFordJhonson(std::vector<int> list, int depth);

    std::deque<int>  _dequeData;
    std::vector<int> _vectorData;
};

std::ostream &operator<<(std::ostream &os, const PmergeMe &pm);