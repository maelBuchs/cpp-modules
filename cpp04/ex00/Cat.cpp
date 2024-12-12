#include "Cat.hpp"

Cat::Cat() : Animal("Cat") { std::cout << "Cat constructor" << std::endl; }

Cat::Cat(const Cat &a) {
  std::cout << "Cat copy constructor" << std::endl;
  *this = a;
}

Cat &Cat::operator=(const Cat &a) {
  std::cout << "Cat assignation operator" << std::endl;
  if (this != &a)
    Animal::operator=(a);
  return *this;
}

Cat::~Cat() { std::cout << "Cat destructor" << std::endl; }

void Cat::makeSound() const { std::cout << "*meow*" << std::endl; }
