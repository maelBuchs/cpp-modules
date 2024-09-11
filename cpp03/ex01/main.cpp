#include "ClapTrap.hpp"
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

    scavTrap = ScavTrap("ScavTrap2");
    scavTrap.attack("apagnan");
    scavTrap.takeDamage(5);
    scavTrap.beRepaired(5);
    scavTrap.guardGate();

    return (0);
}