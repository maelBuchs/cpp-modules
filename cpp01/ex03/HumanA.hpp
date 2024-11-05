#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
  public:
    void setName(std::string Name);
    std::string  getName();
    void attack();
    HumanA(std::string Name, Weapon &Weapon);
    ~HumanA();

  private:
    std::string     _Name;
    Weapon &_Weapon;
};
#endif