#include "Harl.hpp"

int main(int argc, char **argv) {
    Harl Benoit;
    if (argc != 2)
        return 0;
    Benoit.complain(argv[1]);
}