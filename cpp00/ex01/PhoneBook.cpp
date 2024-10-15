#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    _nbrContacts = 0;
}

str PhoneBook::ShortenString(str str)
{
    if (str.length() > 10)
    {
        str.resize(9);
        str += ".";
    }
    return (str);
}

int PhoneBook::AddContact()
{
    str line;

    _Contacts[_nbrContacts].SetFirstName("");
    _Contacts[_nbrContacts].SetLastName("");
    _Contacts[_nbrContacts].SetNickName("");
    _Contacts[_nbrContacts].SetPhoneNumber("");
    _Contacts[_nbrContacts].SetDarkestSecret("");

    while(_Contacts[_nbrContacts].GetFirstName() == "")
    {
        std::cout << "Enter first name: ";
        if (!std::getline(std::cin, line))
                return 1;
        _Contacts[_nbrContacts].SetFirstName(line);
    }
    while(_Contacts[_nbrContacts].GetLastName() == "")
    {
        std::cout << "Enter last name: ";
        if (!std::getline(std::cin, line))
                return 1;
        _Contacts[_nbrContacts].SetLastName(line);
    }
    while(_Contacts[_nbrContacts].GetNickName() == "")
    {
        std::cout << "Enter nickname: ";
        if (!std::getline(std::cin, line))
                return 1;
        _Contacts[_nbrContacts].SetNickName(line);
    }
    while(_Contacts[_nbrContacts].GetPhoneNumber() == "")
    {
        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, line))
                return 1;
        _Contacts[_nbrContacts].SetPhoneNumber(line);
    }
    while(_Contacts[_nbrContacts].GetDarkestSecret() == "")
    {
        std::cout << "Enter darkest secret: ";
        if (!std::getline(std::cin, line))
                return 1;
        _Contacts[_nbrContacts].SetDarkestSecret(line);
    break;
    }
    _nbrContacts = (_nbrContacts + 1) % 8;
    return 0;
}

int PhoneBook::DisplayContacts()
{
    str index;

    std::cout << "###############-C0NT4CT-L15T-##############" << std::endl\
        <<"     Index|First Name| Last Name|  Nickname" << std::endl;
    for(int i = 1; i < 9; i++)
    {
            std::cout << std::setw(10) << i << "|";
            std::cout << std::setw(10) << ShortenString(_Contacts[i - 1].GetFirstName()) << "|";
            std::cout << std::setw(10) << ShortenString(_Contacts[i - 1].GetLastName()) << "|";
            std::cout << std::setw(10) << ShortenString(_Contacts[i - 1].GetNickName()) << std::endl;
    }
    std::cout << "Select an index !" << std::endl;
    if (!std::getline(std::cin, index))
                     return 1;
    int i = std::atoi(index.c_str());
    if (i > 8 || i < 1)
    {
        std::cout << "invalid input" << std::endl;
        return 0;
    }
    i -= 1;
    std::cout << "Name : " << _Contacts[i].GetFirstName() << std::endl;
    std::cout << "LastName : " << _Contacts[i].GetLastName() << std::endl;
    std::cout << "NickName : " << _Contacts[i].GetNickName() << std::endl;
    std::cout << "PhoneNumber : " << _Contacts[i].GetPhoneNumber() << std::endl;
    std::cout << "Darkest Secret : " << _Contacts[i].GetDarkestSecret() << std::endl;
    return 0;
}
