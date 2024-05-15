// #include "phonebook.hpp"
#include <iostream>

int main(void)
{
    // Phonebook phonebook;
    std::string command;

    while (1)
    {
        std::cout << "Enter a command: ";
        std::cin >> command;
        if (command == "ADD")
            std::cout << "bah la faut ADD" << std::endl;
        else if (command == "SEARCH")
            std::cout << "bah la faut SEARCH" << std::endl;
        else if (command == "EXIT")
            std::cout << "bah la faut EXIT" << std::endl;

    }
    return (0);
}