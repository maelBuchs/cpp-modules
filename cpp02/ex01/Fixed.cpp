#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    (*this) = fixed;
}
Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << std::endl;
    _value = int(roundf(num * (1 << _fractionalBit)));
}

Fixed::Fixed(const int num) {
    std::cout << "Int constructor called" << std::endl;
    _value = num << _fractionalBit;
}

Fixed &Fixed::operator=(Fixed const &f) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        _value = f.getRawBits();
    return (*this);
}

float Fixed::toFloat(void) const { return float(_value) / (1 << _fractionalBit); }

int Fixed::toInt(void) const { return (_value >> _fractionalBit); }

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(const int raw) { _value = raw; }

std::ostream &operator<<(std::ostream &o, Fixed const &f) {
    o << f.toFloat();
    return o;
}
