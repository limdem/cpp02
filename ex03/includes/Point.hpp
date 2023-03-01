#include "Fixed.hpp"

class   Point
{
    
    Fixed   x;
    Fixed   y;
        public:
    Point();
    Point(float, float);
    Point(const Point&);
    Point& operator= (const Point&);
    ~Point();
    static bool    bsp(Point const a, Point const b, Point const c, Point const point);
    static float   area(Point const a, Point const b, Point const c);
    static int   in_line(Point const a, Point const b, Point const c);
    Fixed   getX();
    Fixed   getY();
    static void test(Point const a);
};