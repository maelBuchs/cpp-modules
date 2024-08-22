#include "Zombie.hpp"

int main()
{
  Zombie *Billy = newZombie("Billy");
  Billy->announce();
  delete Billy;

  randomChump("Bernard");
}
