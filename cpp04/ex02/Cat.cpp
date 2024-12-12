#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat constructor" << std::endl;
  _brain = new Brain();
}

Cat::Cat(const Cat &a) {
  std::cout << "Cat copy constructor" << std::endl;
  *this = a;
  _brain = new Brain(*a._brain);
}

Cat &Cat::operator=(const Cat &a) { return *this; }

Cat::~Cat() {
  std::cout << "Cat destructor" << std::endl;
  delete _brain;
}

void Cat::makeSound() const { std::cout << "*meow*" << std::endl; }
