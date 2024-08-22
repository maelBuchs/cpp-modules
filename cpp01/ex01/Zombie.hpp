#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

typedef std::string str;
class Zombie
{
  public:
    void announce(void);
    str  getName();
    void setName(str Name);
    Zombie();
    Zombie(str Name);
    ~Zombie();
  private:
    str _Name;
};

Zombie *zombieHorde(int N, str name);
#endif
