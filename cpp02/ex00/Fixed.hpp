#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

typedef std::string str;

class Fixed {
public:
  Fixed(void);
  Fixed(const Fixed &fixed);
  Fixed &operator=(Fixed const &f);
  ~Fixed(void);
  int getRawBits(void) const;
  void setRawBits(int const raw);
private:
	int _value;
	static const int _fractionalBit = 8;
};

#endif