#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# define FIXED_POINT_FRACTIONAL_BITS 8

class   Fixed
{
    private:
        int _fixedPointNumber;
        static const int _fixedPointFractional = FIXED_POINT_FRACTIONAL_BITS;  
    public:
        Fixed();
        Fixed(int const number);
        Fixed(float const number);
        Fixed(const Fixed&);
        ~Fixed();
        Fixed& operator= (const Fixed&);
        Fixed operator+ (const Fixed&) const;
        Fixed operator- (const Fixed&) const;
        Fixed operator* (const Fixed&) const;
        Fixed operator/ (const Fixed&) const;
        Fixed& operator++();
        Fixed   operator++(int);
        Fixed& operator--();
        Fixed   operator--(int);
        
        bool operator> (Fixed  const &other) const;
        bool operator< (Fixed  const &other) const;
        bool operator>= (Fixed  const &other) const;
        bool operator<= (Fixed  const &other) const;
        bool operator== (Fixed  const &other) const;
        bool operator!= (Fixed  const &other) const;
        int getRawBits(void) const;
        void    setRawBits(int const raw);
        int toInt(void) const;
        float   toFloat(void) const;

        static Fixed    min(Fixed&, Fixed&);
        static Fixed    min(Fixed const &, Fixed const &);
        static Fixed    max(Fixed&, Fixed&);
        static Fixed    max(Fixed const &, Fixed const &);
};

std::ostream&   operator<< (std::ostream&, const Fixed&);
#endif