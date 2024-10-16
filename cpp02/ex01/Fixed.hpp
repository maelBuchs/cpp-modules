#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <ostream>

typedef std::string str;

class Fixed {
  public:
    Fixed(void);
    Fixed(const float num);
    Fixed(const int num);
    Fixed(const Fixed &fixed);
    Fixed &operator=(Fixed const &f);
    float  toFloat(void) const;
    int    toInt(void) const;
    ~Fixed(void);
    int  getRawBits(void) const;
    void setRawBits(int const raw);

  private:
    int              _value;
    static const int _fractionalBit = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif