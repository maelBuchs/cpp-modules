#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {

    if (N < 0) {
        std::cout << "Error : N must be positive" << std::endl;
        return (NULL);
    }
    Zombie *zombieTab = new Zombie[N];

    for (int i = 0; i < N; i++) {
        zombieTab[i].setName(name);
    }
    return (zombieTab);
}
