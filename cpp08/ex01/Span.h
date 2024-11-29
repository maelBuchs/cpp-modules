#pragma once

#include <exception>
#include <ostream>
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
  void addSpan(int num);
  friend std::ostream &operator<<(std::ostream &os, const Span &span);

private:
  int _max;
  std::vector<int> _vec;
};