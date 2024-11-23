#include "Circle.hh"
#include "Triangle.hh"
#include <iostream>
#include <memory>
#include <vector>

auto main() -> int
{
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(3.0, Point{ 2.3, 4.3 }));
    shapes.push_back(std::make_unique<Circle>(2.7, Point{ 0.8, 1.9 }));
    shapes.push_back(std::make_unique<Circle>(3.9, Point{ 2.8, 3.6 }));
    shapes.push_back(std::make_unique<Triangle>(Point{ 1.8, 2.5 }, Point{ 4.3, 5.4 }, Point{ 2.1, 8.3 }));
    for (auto i=0ul; i<shapes.size(); ++i) {
        std::cout << i << ": " << shapes[i]->name()
                  << " with area " << shapes[i]->area() << "\n";
    }
}

