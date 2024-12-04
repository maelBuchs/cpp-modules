#pragma once

#include <exception>
#include <iostream>
#include <iterator>
#include <vector>

class Span {
public:
  class FullContainerException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class WrongComparisonException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  Span(int max);
  ~Span();
  void addNumber(int num);
  template <typename Iterator> void addMultiple(Iterator begin, Iterator end) {
      if ((int)_vec.size() + std::distance(begin, end) >= _max )
        throw FullContainerException();
          _vec.insert(_vec.end(), begin, end);
  };
  friend std::ostream &operator<<(std::ostream &os, const Span &span);
  int shortestSpan(void);
  int longestSpan(void);

private:
  int _max;
  std::vector<int> _vec;
};