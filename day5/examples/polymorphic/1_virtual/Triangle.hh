#include "Polygon.hh"
#include <string>

class Triangle : public Polygon<3> {
public:
    Triangle() = default;
    Triangle(Point p1, Point p2, Point p3);
    Triangle(const Triangle&) = default;
    Triangle(Triangle&&) = default;
    Triangle& operator=(const Triangle&) = default;
    Triangle& operator=(Triangle&&) = default;
    double area() const override;
    std::string name() const override { return "Triangle"; }
};
