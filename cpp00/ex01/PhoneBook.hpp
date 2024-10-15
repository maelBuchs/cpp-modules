#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook : public Contact
{
	public:
        int AddContact();
        void SearchContact();
        int DisplayContacts();
        str ShortenString(str str);
        PhoneBook();
	private:
        unsigned int _nbrContacts;
        Contact _Contacts[8];
};


#endif