#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &a) {
  std::cout << "WrongCat copy constructor" << std::endl;
  *this = a;
}

WrongCat &WrongCat::operator=(const WrongCat &a) {
  std::cout << "WrongCat assignment operator" << std::endl;
  if (this != &a)
    WrongAnimal::operator=(a);
  return *this;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor" << std::endl; }

void WrongCat::makeSound() const { std::cout << "*meow*" << std::endl; }
