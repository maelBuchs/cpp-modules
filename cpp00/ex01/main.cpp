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
        std::cin >> command;
        if (std::cin.eof())
            break;
        if (command == "SEARCH")
            MyPhoneBook.DisplayContacts();
        else if (command == "ADD")
            MyPhoneBook.AddContact();
        else if (command == "EXIT")
            break;
    }  
}