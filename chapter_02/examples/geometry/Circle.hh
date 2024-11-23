#ifndef Circle_HH
#define Circle_HH
#include "Point.hh"
#include "Shape.hh"
#include <string>

class Circle : public Shape {
public:
    Circle() = default;
    Circle(double rad, const Point& p);
    Circle(const Circle& cir) = default;
    Circle(Circle&& cir) = default;
    auto operator=(const Circle& cir) -> Circle& = default;
    auto operator=(Circle&& cir) -> Circle& = default;
    void rotate(double phi) override;
    void translate(Point p) override;
    auto area() const -> double override;
    auto perimeter() const -> double override;
    inline auto circumference() const -> double { return perimeter(); }
    auto name() const -> std::string override;

private:
    double r{ 1.0 };
    Point c{}; // Use default constructor of class Point to create c
};

#endif
