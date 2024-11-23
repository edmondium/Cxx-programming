#include "Polygon.hh"
#include <string>
#include <iostream>

class Triangle : public Polygon<3> {
public:
    void sleep(int i, int j=4, int k=9) {
        std::cout << i << "\t" << j << "\t" << k << "\n";
    }
    void sleeptest()
    {
        sleep(1);
        sleep(9,3,4);
        sleep(3,4);
    }
    Triangle() = default;
    Triangle(Point p1, Point p2, Point p3);
    Triangle(const Triangle&) = default;
    Triangle(Triangle&&) = default;
    auto operator=(const Triangle&) -> Triangle& = default;
    auto operator=(Triangle &&) -> Triangle& = default;
    auto area() const -> double override;
    auto name() const -> std::string override { return "Triangle"; }
};
