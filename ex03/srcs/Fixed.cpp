#include "../includes/Fixed.hpp"
#include <iostream>
#include <math.h>

Fixed::Fixed()
{
    this->fixed_point_number = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const number)
{
    int inbr;

    inbr = number << binary_point;
    this->fixed_point_number = inbr;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const number)
{
    int     exponent;

    exponent = 1 << binary_point;
    this->fixed_point_number = roundf(number * exponent);
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
    this->fixed_point_number = src.getRawBits();
    return (*this);
}

Fixed Fixed::operator+ (const Fixed& src) const
{
    Fixed   plus;

    plus.setRawBits(this->fixed_point_number + src.getRawBits());
    return (plus);
}

Fixed Fixed::operator- (const Fixed& src) const
{
    Fixed   minus;

    minus.setRawBits(this->fixed_point_number - src.getRawBits());
    return (minus);
}

Fixed Fixed::operator* (const Fixed& src) const
{
    Fixed   times;

    times.setRawBits(this->fixed_point_number * src.getRawBits()/ (1 << binary_point));
    return (times);
}

Fixed Fixed::operator/ (const Fixed& src) const
{
    Fixed   div;

    div.setRawBits(this->fixed_point_number * (1 << binary_point) / src.getRawBits());
    return (div);
}

Fixed& Fixed::operator++()
{
    this->fixed_point_number++;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed incr(*this);

    this->operator++();
    return (incr);
}

bool Fixed::operator> (Fixed  const &src) const
{ 
    return (this->fixed_point_number > src.getRawBits());
}

bool Fixed::operator< (Fixed  const &src) const
{ 
    return (this->fixed_point_number < src.getRawBits());
}

bool Fixed::operator>= (Fixed  const &src) const
{ 
    return (this->fixed_point_number >= src.getRawBits());
}

bool Fixed::operator<= (Fixed  const &src) const
{ 
    return (this->fixed_point_number <= src.getRawBits());
}

bool Fixed::operator== (Fixed  const &src) const
{ 
    return (this->fixed_point_number == src.getRawBits());
}

bool Fixed::operator!= (Fixed  const &src) const
{ 
    return (this->fixed_point_number != src.getRawBits());
}

Fixed::~Fixed()
{
    std::cout << "Default destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point_number);
}

void    Fixed::setRawBits(int const raw)
{
    
    this->fixed_point_number = raw;
}

int Fixed::toInt(void) const
{
    int number;

    number = fixed_point_number >> binary_point;
    return (number);
}

float   Fixed::toFloat(void) const
{
    float     exponent;
    float   number;

    exponent = 1 << binary_point;
    number = fixed_point_number / exponent;
    return (number);
}

Fixed Fixed::min(Fixed& fix1, Fixed& fix2)
{ 
    if (fix1 <= fix2)
        return (fix1);
    else
        return (fix2);
}

Fixed Fixed::min(Fixed const &fix1, Fixed const & fix2)
{ 
    if (fix1 <= fix2)
        return (fix1);
    else
        return (fix2);
}

Fixed Fixed::max(Fixed& fix1, Fixed& fix2)
{ 
    if (fix1 >= fix2)
        return (fix1);
    else
        return (fix2);
}

Fixed Fixed::max(Fixed const &fix1, Fixed const & fix2)
{ 
    if (fix1 >= fix2)
        return (fix1);
    else
        return (fix2);
}

std::ostream&   operator<< (std::ostream& os, const Fixed& src)
{
    os << src.toFloat();
    return (os);
}