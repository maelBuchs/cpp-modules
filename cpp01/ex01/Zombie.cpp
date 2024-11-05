#include "Zombie.hpp"
Zombie::Zombie(std::string Name) {
    _Name = Name;
    std::cout << _Name << " just woke up" << std::endl;
}

Zombie::Zombie() { _Name = "Zombie"; }

Zombie::~Zombie() { std::cout << _Name << " went back where he came from" << std::endl; }

void Zombie::announce(void) { std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

std::string Zombie::getName(void) { return (_Name); }

void Zombie::setName(std::string Name) {
    _Name = Name;
    std::cout << _Name << " just woke up" << std::endl;
}
