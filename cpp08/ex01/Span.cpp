#include "Span.h"
#include <algorithm>
#include <vector>

Span::Span(int max) : _max(max) {}
Span::~Span() {}

void Span::addNumber(int num) {
  if ((int)_vec.size() >= _max)
    throw FullContainerException();
  _vec.push_back(num);
}

const char *Span::FullContainerException::what() const throw() {
  return "Container is full.";
}

const char *Span::WrongComparisonException::what() const throw() {
  return "Comparison operation is invalid.";
}

std::ostream &operator<<(std::ostream &os, const Span &span) {
  for (int i = 0; i < (int)span._vec.size(); i++)
    os << "vec [" << i << "] = " << span._vec[i] << "\n";
  return os;
}

int Span::shortestSpan(void) {

  std::vector<int> vec = _vec;
  std::sort(vec.begin(), vec.end());
  int span = vec[1] - vec[0];
  for (int i = 1; i < (int)vec.size() - 1; i++)
    if (vec[i + 1] - vec[i] < span)
      span = vec[i + 1] - vec[i];
  return span;
}

int Span::longestSpan(void) {
  int min = *std::min_element(_vec.begin(), _vec.end());
  int max = *std::max_element(_vec.begin(), _vec.end());

  return max - min;
}
