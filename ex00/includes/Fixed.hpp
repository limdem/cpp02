#ifndef FIXED_HPP
# define FIXED_HPP

# define FIXED_POINT_FRACTIONAL_BITS 8

class   Fixed
{
    private:
        int _fixedPointInteger;
        static const int _fixedPointFractional = FIXED_POINT_FRACTIONAL_BITS;  
    public:
        Fixed();
        Fixed(const Fixed&);
        Fixed& operator= (const Fixed&);
        ~Fixed();
        int getRawBits(void) const;
        void    setRawBits(int const raw);
};
#endif