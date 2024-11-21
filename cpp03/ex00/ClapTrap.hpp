#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap {
public:
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  ClapTrap &operator=(const ClapTrap &other);
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &c);
  ~ClapTrap();

private:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoint;
  unsigned int _attackDamage;
};

#endif