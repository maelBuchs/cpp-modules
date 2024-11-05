#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
  public:
    void announce(void);
    std::string  getName();
    void setName(std::string Name);
    Zombie();
    Zombie(std::string Name);
    ~Zombie();

  private:
    std::string _Name;
};

Zombie *zombieHorde(int N, std::string name);
#endif
