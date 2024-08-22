#include "Zombie.hpp"

Zombie::Zombie(str Name)
{
  _Name = Name;
  std::cout << _Name << " just woke up" << std::endl;
}

Zombie::~Zombie()
{
  std::cout << _Name << " went back where he came from" << std::endl;
}

void Zombie::announce(void)
{
  std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

str Zombie::getName(void)
{
  return(_Name);
}

void Zombie::setName(str Name)
{
  _Name = Name;
}
