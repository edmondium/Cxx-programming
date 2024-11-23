#include "Circle.hh"

constexpr double pi = 3.141592653589793;

Circle::Circle(double rad, const Point& p)
    : r{ rad }
    , c{ p }
{
}

auto Circle::name() const -> std::string
{
    return "Circle";
}

auto Circle::area() const -> double
{
    return pi * r * r;
}

auto Circle::perimeter() const -> double
{
    return 2 * pi * r;
}

void Circle::rotate(double phi) { phi = 0; }

void Circle::translate(Point p)
{
    c += p;
}
