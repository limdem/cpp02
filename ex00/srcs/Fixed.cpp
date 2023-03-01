#include "../includes/Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
    this->_fixedPointInteger = 0;
    std::cout << "Default constructor called" << std::endl;
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