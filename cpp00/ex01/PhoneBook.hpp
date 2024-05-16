#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook : public Contact
{
	public:
        void AddContact();
        void SearchContact();
        void DisplayContacts();
        str ShortenString(str str);
        PhoneBook();
	private:
        Contact _Contacts[8];
};


#endif