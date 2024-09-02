#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
public:
  void setName(str Name);
  str getName();
  void setWeapon(Weapon &Weapon);
  Weapon *getWeapon();
  void attack();
  HumanB(Weapon *Weapon, str Name);
  HumanB(str Name);
  ~HumanB();

private:
  str _Name;
  Weapon *_Weapon;
};
#endif