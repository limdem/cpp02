#include "../includes/Point.hpp"
#include <math.h>

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(float fix1, float fix2)
:x(fix1), y(fix2)
{}

Point::Point(const Point& src) : x(src.x), y(src.y)
{}

Point& Point::operator= (const Point&src)
{
    this->x = src.x;
    this->y = src.y;
    return (*this);
}

Point::~Point(){}

float   Point::area(Point pt1, Point pt2, Point pt3)
{
    float   cal1;
    float   cal2;
    float   cal3;

    cal1 = pt1.getX().toFloat() * (pt2.getY().toFloat() - pt3.getY().toFloat());
    cal2 = pt2.getX().toFloat() * (pt3.getY().toFloat() - pt1.getY().toFloat());
    cal3 = pt3.getX().toFloat() * (pt1.getY().toFloat() - pt2.getY().toFloat());
    return (std::abs(cal1 + cal2 + cal3) / 2);
}

int   Point::in_line(Point pt1, Point pt2, Point pt3)
{
    int a;
    int b;

    a = ((pt3.getY().toFloat() - pt2.getY().toFloat()) / (pt3.getX().toFloat() - pt2.getX().toFloat()));
    b = pt2.getY().toFloat() - a * pt2.getX().toFloat();
    if (a * pt1.getX().toFloat() + b == pt1.getY().toFloat())
        return (1);
    else
        return (0);
}

bool    Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
    float   A;
    float   A_p;

    if (Point::in_line(point, a, b))
        return (0);
    
    if (Point::in_line(point, b, c))
        return (0);
    if (Point::in_line(point, a, c))
        return (0);
    A = Point::area(a, b, c);
    A_p = Point::area(point, b, c);
    A_p += Point::area(a, point, c);
    A_p += Point::area(a, b, point);
    return (A == A_p);
}

Fixed Point::getX()
{
    return (this->x);
}

Fixed Point::getY()
{
    return (this->y);
}