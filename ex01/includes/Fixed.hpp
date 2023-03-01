#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# define FIXED_POINT_FRACTIONAL_BITS 8

class   Fixed
{
    private:
        int _fixedPointInteger;
        static const int _fixedPointFractional = FIXED_POINT_FRACTIONAL_BITS;  
    public:
        Fixed();
        Fixed(int const number);
        Fixed(float const number);
        Fixed(const Fixed&);
        Fixed& operator= (const Fixed&);
        ~Fixed();
        int getRawBits(void) const;
        void    setRawBits(int const raw);
        int toInt(void) const;
        float   toFloat(void) const;
};
std::ostream&   operator<< (std::ostream&, const Fixed&);
#endif