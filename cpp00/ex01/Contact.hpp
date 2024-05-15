#ifndef CONATCT_HPP
#define CONTACT_HPP
#include <iostream>
class Contact
{
	public:

		void SetFirstName(std::string FirstName);
		void SetLastName(std::string LastName);
		void SetNickName(std::string NickName);
		void SetPhoneNumber(std::string PhoneNumber);
		void SetDarkestSecret(std::string DarkestSecret);
		std::string GetFirstName();
		std::string GetLastName();
		std::string GetNickName();
		std::string GetPhoneNumber();
		std::string GetDarkestSecret();
		Contact(std::string, std::string, std::string, std::string, std::string);
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;
};

Contact::Contact(std::string FirstName, std::string LastName, std::string NickName, std::string PhoneNumber, std::string DarkestSecret)
{
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->NickName = NickName;
	this->PhoneNumber = PhoneNumber;
	this->DarkestSecret = DarkestSecret;
}

#endif