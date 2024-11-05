#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon &Weapon) : _Name(Name), _Weapon(Weapon) {}

HumanA::~HumanA() {}

void HumanA::setName(std::string Name) { _Name = Name; }

std::string HumanA::getName(void) { return (_Name); }

void HumanA::attack() {
    std::cout << getName() << " attacks with their " << _Weapon.getType() << std::endl;
}