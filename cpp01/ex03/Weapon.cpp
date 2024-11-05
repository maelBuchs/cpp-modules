#include "Weapon.hpp"

Weapon::Weapon() { setType("deadly weapon"); }

Weapon::Weapon(std::string Type) : _Type(Type) {}

Weapon::~Weapon() {}

std::string &Weapon::getType() {
    std::string &ref = _Type;
    return (ref);
}

void Weapon::setType(std::string Type) { _Type = Type; }