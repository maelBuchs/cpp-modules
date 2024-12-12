#include "Dog.hpp"

Dog::Dog() : Animal("Dog") { std::cout << "Dog constructor" << std::endl; }

Dog::Dog(const Dog &a) {
  std::cout << "Dog copy constructor" << std::endl;
  *this = a;
}

Dog &Dog::operator=(const Dog &a) { return *this; }

Dog::~Dog() { std::cout << "Dog destructor" << std::endl; }

void Dog::makeSound() const { std::cout << "*BARK*" << std::endl; }
