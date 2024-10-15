#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

typedef std::string str;
class Contact {
  public:
    void SetFirstName(str FirstName);
    void SetLastName(str LastName);
    void SetNickName(str NickName);
    void SetPhoneNumber(str PhoneNumber);
    void SetDarkestSecret(str DarkestSecret);
    str  GetFirstName();
    str  GetLastName();
    str  GetNickName();
    str  GetPhoneNumber();
    str  GetDarkestSecret();
    Contact();

  private:
    str _FirstName;
    str _LastName;
    str _NickName;
    str _PhoneNumber;
    str _DarkestSecret;
};

#endif