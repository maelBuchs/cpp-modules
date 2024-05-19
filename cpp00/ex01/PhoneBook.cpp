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
    str index;

    std::cout << "###############-C0NT4CT-L15T-##############" << std::endl\
        <<"     Index|First Name| Last Name|  Nickname" << std::endl;
    for(int i = 1; i < 9; i++)
    {
        // if (_Contacts[i - 1].GetFirstName()[0] != '\0')
        // {
            std::cout << std::setw(10) << i << "|";
            std::cout << std::setw(10) << ShortenString(_Contacts[i - 1].GetFirstName()) << "|";
            std::cout << std::setw(10) << ShortenString(_Contacts[i - 1].GetLastName()) << "|";
            std::cout << std::setw(10) << ShortenString(_Contacts[i - 1].GetNickName()) << std::endl;
        // }
    }
    std::cout << "Select an index !" << std::endl;
    std::cin >> index;
    int i = std::atoi(index.c_str());
    if (i > 8 || i < 1)
    {
        std::cout << "invalid input" << std::endl;
        return ;
    }
    i -= 1;
    std::cout << "Name : " << _Contacts[i].GetFirstName() << std::endl;
    std::cout << "LastName : " << _Contacts[i].GetLastName() << std::endl;
    std::cout << "NickName : " << _Contacts[i].GetNickName() << std::endl;
    std::cout << "PhoneNumber : " << _Contacts[i].GetPhoneNumber() << std::endl;
    std::cout << "Darkest Secret : " << _Contacts[i].GetDarkestSecret() << std::endl;
}
