#include "Weapon.hpp"

Weapon::Weapon() { setType("deadly weapon"); }

Weapon::Weapon(str Type) : _Type(Type) {}

Weapon::~Weapon() {}

str &Weapon::getType() {
    str &ref = _Type;
    return (ref);
}

void Weapon::setType(str Type) { _Type = Type; }