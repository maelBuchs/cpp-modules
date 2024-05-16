#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){}

str PhoneBook::ShortenString(str str)
{
    if (str.length() > 10)
    {
        str.resize(9);
        str += ".";
    }
    return (str);
}

void PhoneBook::AddContact()
{
    str line;

    for (int i = 0; i < 8; i++)
    {
        if (_Contacts[i].GetFirstName() == "")
        {
            while(_Contacts[i].GetFirstName() == "")
            {
                std::cout << "Enter first name: ";
                std::cin >> line;
                _Contacts[i].SetFirstName(line);
            }
            while(_Contacts[i].GetLastName() == "")
            {
                std::cout << "Enter last name: ";
                std::cin >> line;
                _Contacts[i].SetLastName(line);
            }
            while(_Contacts[i].GetNickName() == "")
            {
                std::cout << "Enter nickname: ";
                std::cin >> line;
                _Contacts[i].SetNickName(line);
            }
            while(_Contacts[i].GetPhoneNumber() == "")
            {
                std::cout << "Enter phone number: ";
                std::cin >> line;
                _Contacts[i].SetPhoneNumber(line);
            }
            while(_Contacts[i].GetDarkestSecret() == "")
            {
                std::cout << "Enter darkest secret: ";
                std::cin >> line;
                _Contacts[i].SetDarkestSecret(line);
            }
            break;
        }
    }
}

void PhoneBook::DisplayContacts()
{
    std::cout << "####################-W3LC0M3-T0-PH0N3B00K-####################" << std::endl <<"     Index|First Name| Last Name|  Nickname|  PhoneNum|DarkSecret" << std::endl;
    for(int i = 0; i < 8; i++)
    {
        if (_Contacts[i].GetFirstName() != "")
        {
            std::cout << std::setw(10);
            std::cout << i << "|";
            std::cout << std::setw(10);
            std::cout << ShortenString(_Contacts[i].GetFirstName()) << "|";
            std::cout << std::setw(10);
            std::cout << ShortenString(_Contacts[i].GetLastName()) << "|";
            std::cout << std::setw(10);
            std::cout << ShortenString(_Contacts[i].GetNickName()) << "|";
            std::cout << std::setw(10);
            std::cout << ShortenString(_Contacts[i].GetPhoneNumber()) << "|";
            std::cout << std::setw(10);
            std::cout << ShortenString(_Contacts[i].GetDarkestSecret()) << std::endl;
        }
    }
}
