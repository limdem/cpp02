#include "../includes/Fixed.hpp"
#include <iostream>
#include <math.h>

Fixed::Fixed()
{
    this->_fixedPointInteger = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const number)
{
    int inbr;

    inbr = number << _fixedPointFractional;
    this->_fixedPointInteger = inbr;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const number)
{
    float     exponent;

    exponent = 1 << _fixedPointFractional;
    this->_fixedPointInteger = roundf(number * exponent);
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed& Fixed::operator= (const Fixed& src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixedPointInteger = src.getRawBits();
    return (*this);
}

std::ostream&   operator<< (std::ostream& os, const Fixed& src)
{
    os << src.toFloat();
    return (os);
}

Fixed::~Fixed()
{
    std::cout << "Default destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointInteger);
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixedPointInteger = raw;
}

int Fixed::toInt(void) const
{
    int number;

    number = _fixedPointInteger >> _fixedPointFractional;
    return (number);
}

float   Fixed::toFloat(void) const
{
    float     exponent;
    float   number;

    exponent = 1 << _fixedPointFractional;
    number = _fixedPointInteger / exponent;
    return (number);
}