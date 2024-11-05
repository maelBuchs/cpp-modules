#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>


class Weapon {
  public:
    std::string &getType();
    void setType(std::string Type);
    Weapon();
    Weapon(std::string Type);
    ~Weapon();

  private:
    std::string _Type;
};

#endif