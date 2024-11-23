#include "Point.hh"
#include <iostream>

Point::Point(double x, double y)
    : X{ x }
    , Y{ y }
{
}

auto Point::operator+=(const Point& p) -> Point&
{
    X += p.X;
    Y += p.Y;
    return *this;
}

auto Point::operator-=(const Point& p) -> Point&
{
    X -= p.X;
    Y -= p.Y;
    return *this;
}

auto Point::operator+(const Point& p) const -> Point
{
    return { X + p.X, Y + p.Y };
}

auto Point::operator-(const Point& p) const -> Point
{
    return { X - p.X, Y - p.Y };
}

auto Point::operator*(const Point& p) const -> double
{
    return (X * p.X + Y * p.Y);
}

auto Point::operator*(double f) const -> Point
{
    return { f * X, f * Y };
}

auto operator*(double f, const Point& p) -> Point
{
    return { f * p.X, f * p.Y };
}

auto operator<<(std::ostream& os, const Point& p) -> std::ostream&
{
    os << "(" << p.X << ", " << p.Y << ")";
    return os;
}
