#ifndef Shape_HH
#define Shape_HH

#include "Point.hh"
#include <string>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void rotate(double) = 0;
    virtual void translate(Point) = 0;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string name() const = 0;
};

#endif
