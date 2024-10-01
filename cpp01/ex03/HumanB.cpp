#include "HumanB.hpp"

HumanB::HumanB(Weapon *Weapon, str Name) : _Name(Name), _Weapon(Weapon) {}

HumanB::HumanB(str Name) : _Name(Name) {}

HumanB::~HumanB() {}

void HumanB::setName(str Name) { _Name = Name; }

str HumanB::getName(void) { return (_Name); }

Weapon *HumanB::getWeapon() { return (_Weapon); }

void HumanB::setWeapon(Weapon &Weapon) { _Weapon = &Weapon; }

void HumanB::attack() {
  std::cout << getName() << " attacks with their " << (*_Weapon).getType()
            << std::endl;
}