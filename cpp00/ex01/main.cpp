#include <iostream>
#include "PhoneBook.hpp"

int main()
{
    std::string command;
    PhoneBook MyPhoneBook;
    Contact contact;
    while (42)
    {
        std::cout << "Enter a command: ";
        if (!std::getline(std::cin, command))
            return 1;
        if ((command == "SEARCH" && MyPhoneBook.DisplayContacts())
            || (command == "ADD" && MyPhoneBook.AddContact())
            || command == "EXIT")
            return 0;
        else 
            std::cout << "COMMANDS : SEARCH | ADD | EXIT" << std::endl;
    }  
}