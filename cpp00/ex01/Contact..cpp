#include "Contact.hpp"

std::string Contact::GetFirstName(){ return (this->FirstName);}
std::string Contact::GetLastName(){ return (this->LastName);}
std::string Contact::GetNickName(){ return (this->NickName);}
std::string Contact::GetPhoneNumber(){ return (this->PhoneNumber);}
std::string Contact::GetDarkestSecret(){ return (this->DarkestSecret);}
void Contact::SetFirstName(std::string FirstName){ this->FirstName = FirstName;}
void Contact::SetLastName(std::string LastName){ this->LastName = LastName;}
void Contact::SetNickName(std::string NickName){ this->NickName = NickName;}
void Contact::SetPhoneNumber(std::string PhoneNumber){ this->PhoneNumber = PhoneNumber;}
void Contact::SetDarkestSecret(std::string DarkestSecret){ this->DarkestSecret = DarkestSecret;}
