#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  ClapTrap clapTrap("ClapTrap");

  clapTrap.attack("target");
  clapTrap.takeDamage(5);
  clapTrap.beRepaired(5);

  ScavTrap scavTrap("ScavTrap");

  scavTrap.attack("apagnan");
  scavTrap.takeDamage(5);
  scavTrap.beRepaired(5);
  scavTrap.guardGate();

  FragTrap fragTrap("FragTrap");

  fragTrap.attack("apagnan");
  fragTrap.takeDamage(5);
  fragTrap.beRepaired(5);
  fragTrap.highFivesGuys();

  return (0);
}