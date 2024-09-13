#include "FragTrap.hpp"
#include <string>

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap() : ClapTrap("FragTrap", 100, 50, 20) {
    std::cout << "FragTrap default constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap &c) : ClapTrap(c) {
    std::cout << "FragTrap copy constructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap() { std::cout << "FragTrap destructor called" << std::endl; }

void FragTrap::highFivesGuys() { std::cout << _name << " is high five-ing guys" << std::endl; }

void FragTrap::attack(const std::string &target) {
    if (_energyPoint == 0 || _hitPoints == 0) {
        std::cout << _name << " has no points left!" << std::endl;
        return;
    }
    std::cout << _name << " attack (but faster than a ClapTrap because he is a FragTrap) " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoint--;
    std::cout << _name << " has " << _energyPoint << " energy points left!" << std::endl;
}
