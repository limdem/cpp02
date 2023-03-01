#include "../includes/Point.hpp"

int main()
{
    /*
    Point   a(0, 0);
    Point   b(10, 30);
    Point   c(20, 0);
    Point   point(10, 15);
    */
    Point   a(0, 0);
    Point   b(10, 30);
    Point   c(20, 0);
    Point   point(30, 15);   
    
    if (Point::bsp(a, b, c, point))
        std::cout << "INSIDE" << std::endl;
    else
        std::cout << "OUTSIDE" << std::endl;
    
    return (0);
}