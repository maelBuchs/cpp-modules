#include "ScavTrap.hpp"
#include <string>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
  std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap("ScavTrap", 100, 50, 20) {
  std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &c) : ClapTrap(c) {
  std::cout << "ScavTrap copy constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  if (this != &other)
    ClapTrap::operator=(other);
  return (*this);
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << _name << " is now in gatekeeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (_energyPoint == 0 || _hitPoints == 0) {
    std::cout << _name << " has no points left!" << std::endl;
    return;
  }
  std::cout << _name
            << " attack (but better than a ClapTrap because he is a ScavTrap) "
            << target << ", causing " << _attackDamage << " points of damage!"
            << std::endl;
  _energyPoint--;
  std::cout << _name << " has " << _energyPoint << " energy points left!"
            << std::endl;
}
