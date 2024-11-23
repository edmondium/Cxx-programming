#ifndef Polygon_HH
#define Polygon_HH
#include <array>
#include <cmath>
#include "Shape.hh"

template <unsigned int NV>
class Polygon : public Shape {
    static_assert(NV > 2, "Can't have polygon with less than 3 sides");
public:
    Polygon() = default;
    Polygon(const Polygon&) = default;
    Polygon(Polygon&&) = default;
    auto operator=(const Polygon& pg) -> Polygon& = default;
    auto operator=(Polygon &&) -> Polygon& = default;
    constexpr auto n_vertexes() const { return NV; }
    auto name() const -> std::string override { return "Polygon<" + std::to_string(NV) + ">"; }

    auto perimeter() const -> double override
    {
        double ans = 0;
        for (size_t i = 1; i < vertex.size(); ++i) {
            ans += sqrt((vertex[i] - vertex[i - 1]) * (vertex[i] - vertex[i - 1]));
        }
        ans += sqrt((vertex.front() - vertex.back()) * (vertex.front() - vertex.back()));
        return ans;
    }
    void translate(Point p) override {
        for (auto& pt : vertex)
            pt += p;
    }

    void rotate(double phi) override{
        Point center;
        for (auto pt : vertex)
            center += pt;
        center = (1.0 / NV) * center;
        double ct = cos(phi), st = sin(phi);
        for (auto& pt : vertex) {
            auto rel = pt - center;
            pt = center + Point(ct * rel.X + st * rel.Y, -st * rel.X + ct * rel.Y);
        }
    }


protected:
    std::array<Point, NV> vertex;
};

#endif
