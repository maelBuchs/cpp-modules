#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

typedef std::string str;

class Weapon {
public:
  str &getType();
  void setType(str Type);
  Weapon();
  Weapon(str Type);
  ~Weapon();

private:
  str _Type;
};

#endif