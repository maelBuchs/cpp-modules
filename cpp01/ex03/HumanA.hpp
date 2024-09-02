#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
public:
  void setName(str Name);
  str getName();
  void attack();
  HumanA(str Name, Weapon &Weapon);
  ~HumanA();

private:
  str _Name;
  Weapon &_Weapon;
};
#endif