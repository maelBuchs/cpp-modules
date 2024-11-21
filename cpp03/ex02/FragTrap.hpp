#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
public:
  FragTrap();
  FragTrap(std::string name);
  FragTrap(const FragTrap &c);
  void highFivesGuys();
  ~FragTrap();
  void attack(const std::string &target);
  FragTrap &operator=(const FragTrap &other);
};

#endif