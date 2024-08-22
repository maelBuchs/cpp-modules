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
    Zombie(str Name);
    ~Zombie();
  private:
    str _Name;
};

void randomChump(str name);
Zombie *newZombie(str name);
#endif
