#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {
  public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &c);
    void guardGate();
    ~ScavTrap();
    void      attack(const std::string &target);
    ScavTrap &operator=(const ScavTrap &other);
};

#endif