#ifndef Shape_HH
#define Shape_HH

#include "Point.hh"
#include <string>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void rotate(double) = 0;
    virtual void translate(Point) = 0;
    virtual auto area() const -> double = 0;
    virtual auto perimeter() const -> double = 0;
    virtual auto name() const -> std::string = 0;
};

#endif
