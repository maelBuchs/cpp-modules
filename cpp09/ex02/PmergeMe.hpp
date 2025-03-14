#pragma once

#include <deque>
#include <exception>
#include <ostream>
#include <iostream>
#include <string>
#include <vector>
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

    std::deque<int>  _dequeData;
    std::vector<int> _vectorData;
};

std::ostream &operator<<(std::ostream &os, const PmergeMe &pm);