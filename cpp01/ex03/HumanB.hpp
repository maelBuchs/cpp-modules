#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
  public:
    void        setName(std::string Name);
    std::string getName();
    void        setWeapon(Weapon &Weapon);
    Weapon     *getWeapon();
    void        attack();
    HumanB(Weapon *Weapon, std::string Name);
    HumanB(std::string Name);
    ~HumanB();

  private:
    std::string _Name;
    Weapon     *_Weapon;
};
#endif