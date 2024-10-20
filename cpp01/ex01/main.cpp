#include "Zombie.hpp"

int main() {

    int size = 4;

    Zombie *horde = zombieHorde(size, "Bernard");

    for (int i = 0; i < size; i++) {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}