#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(std::string type) {
	std::cout << "Animal constructor" << std::endl;
	  _type = type;
}

Animal::Animal(const Animal &a) {
	std::cout << "Animal copy constructor" << std::endl;
	  *this = a;
}

Animal &Animal::operator=(const Animal &a) {
	  return *this;
}

Animal::~Animal() { std::cout << "Animal destructor" << std::endl;
}

std::string Animal::getType() const {
	  return _type;
}

void Animal::setType(std::string type) {
	  _type = type;
}

void Animal::makeSound() const {
	  std::cout << "Animal sound" << std::endl;
}
