#include "HumanB.hpp"

HumanB::HumanB(Weapon *Weapon, std::string Name) : _Name(Name), _Weapon(Weapon) {}

HumanB::HumanB(std::string Name) : _Name(Name) {}

HumanB::~HumanB() {}

void HumanB::setName(std::string Name) { _Name = Name; }

std::string HumanB::getName(void) { return (_Name); }

Weapon *HumanB::getWeapon() { return (_Weapon); }

void HumanB::setWeapon(Weapon &Weapon) { _Weapon = &Weapon; }

void HumanB::attack() {
    if (_Weapon) {
        std::cout << getName() << " attacks with their " << _Weapon->getType() << std::endl;
    } else {
        std::cout << getName() << " has no weapon to attack with." << std::endl;
    }
}