#include "HumanA.hpp"

HumanA::HumanA(str Name, Weapon &Weapon) : _Name(Name), _Weapon(Weapon) {}

HumanA::~HumanA() {}

void HumanA::setName(str Name) { _Name = Name; }

str HumanA::getName(void) { return (_Name); }

void HumanA::attack() {
    std::cout << getName() << " attacks with their " << _Weapon.getType() << std::endl;
}