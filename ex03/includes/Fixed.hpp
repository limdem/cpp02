#ifndef FIXED_H
# define FIXED_H
# include <iostream>

class   Fixed
{
    private:
        int fixed_point_number;
        static const int binary_point = 8;  
    public:
        Fixed();
        Fixed(int const number);
        Fixed(float const number);
        Fixed(const Fixed&);
        Fixed& operator= (const Fixed&);
        Fixed operator+ (const Fixed&) const;
        Fixed operator- (const Fixed&) const;
        Fixed operator* (const Fixed&) const;
        Fixed operator/ (const Fixed&) const;
        Fixed& operator++();
        Fixed   operator++(int);
        
        bool operator> (Fixed  const &other) const;
        bool operator< (Fixed  const &other) const;
        bool operator>= (Fixed  const &other) const;
        bool operator<= (Fixed  const &other) const;
        bool operator== (Fixed  const &other) const;
        bool operator!= (Fixed  const &other) const;
        ~Fixed();
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