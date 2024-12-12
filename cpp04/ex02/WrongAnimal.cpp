#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
  std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
  std::cout << "WrongAnimal constructor" << std::endl;
  _type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a) {
  std::cout << "WrongAnimal copy constructor" << std::endl;
  *this = a;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a) {
  std::cout << "WrongAnimal assignment operator" << std::endl;
  if (this != &a)
    _type = a._type;
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor" << std::endl;
}

std::string WrongAnimal::getType() const { return _type; }

void WrongAnimal::setType(std::string type) { _type = type; }

void WrongAnimal::makeSound() const {
  std::cout << "Definitely not a Cat sound" << std::endl;
}
