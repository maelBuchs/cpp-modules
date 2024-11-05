#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
  public:
    void announce(void);
    std::string  getName();
    void setName(std::string Name);
    Zombie(std::string Name);
    ~Zombie();

  private:
    std::string _Name;
};

void    randomChump(std::string name);
Zombie *newZombie(std::string name);
#endif
