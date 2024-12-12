#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain constructor" << std::endl; }

Brain::~Brain() { std::cout << "Brain destructor" << std::endl; }

Brain::Brain(const Brain &src) {
  std::cout << "Brain copy constructor" << std::endl;
  *this = src;
}

Brain &Brain::operator=(const Brain &src) {
  std::cout << "Brain assignation operator" << std::endl;
  if (this != &src) {
    for (int i = 0; i < 100; i++)
      ideas[i] = src.ideas[i];
  }
  return *this;
}