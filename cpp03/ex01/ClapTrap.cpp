#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string &target) {
  if (_energyPoint == 0 || _hitPoints == 0) {
    std::cout << _name << " has no points left!" << std::endl;
    return;
  }
  std::cout << _name << " attack " << target << ", causing " << _attackDamage
            << " points of damage!" << std::endl;
  _energyPoint--;
  std::cout << _name << " has " << _energyPoint << " energy points left!"
            << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << _name << " is already dead!" << std::endl;
    return;
  }
  std::cout << _name << " take " << amount << " points of damage!" << std::endl;
  if (amount > _hitPoints) {
    std::cout << _name << " is dead!" << std::endl;
    _hitPoints = 0;
    return;
  }
  _hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energyPoint == 0 || _hitPoints == 0) {
    std::cout << _name << " has no points left!" << std::endl;
    return;
  }
  std::cout << _name << " is repaired by " << amount << " points!" << std::endl;
  _energyPoint--;
  std::cout << _name << " has " << _energyPoint << " energy points left!"
            << std::endl;
  _hitPoints += amount;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  _name = other._name;
  _hitPoints = other._hitPoints;
  _energyPoint = other._energyPoint;
  _attackDamage = other._attackDamage;
  return (*this);
}

ClapTrap::ClapTrap() {
  _name = "Bernard";
  _hitPoints = 10;
  _energyPoint = 10;
  _attackDamage = 0;
  std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
  _name = name;
  _hitPoints = 10;
  _energyPoint = 10;
  _attackDamage = 0;
  std::cout << "ClapTrap constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c) {
  if (this != &c)
    (*this) = c;
  std::cout << "ClapTrap copy constructor" << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap destructor" << std::endl; }
