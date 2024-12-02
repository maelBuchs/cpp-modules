#include "Span.h"

Span::Span(int max):_max(max){}
Span::~Span(){}

void Span::addNumber(int num)
{
    if((int)_vec.size() >= _max)
        throw FullContainerException(); 
    _vec.push_back(num);
}

const char *Span::FullContainerException::what() const throw() {
    return "Container is full.";
}

const char *Span::WrongComparisonException::what() const throw() {
    return "Comparison operation is invalid.";
}

std::ostream &operator<<(std::ostream& os, const Span& span)
{
    for (int i = 0; i < (int)span._vec.size(); i++)
        os << "vec [" << i << "] = " << span._vec[i] << "\n";
    return os;
}

void Span::addMultiple(int num)
{
    if((int)_vec.size() >= _max)
        throw FullContainerException();
    (void) num;
    _vec.insert(_vec.end(), _vec.begin(), _vec.end());
}