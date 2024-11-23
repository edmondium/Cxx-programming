#ifndef Point_HH
#define Point_HH
class ostream;
struct Point {
    double X = 0, Y = 0;
    Point() = default;
    Point(const Point&) = default;
    Point(Point&&) = default;
    auto operator=(const Point& p) -> Point& = default;
    auto operator=(Point&& p) -> Point& = default;
    Point(double x, double y);
    auto operator+=(const Point& p) -> Point&;
    auto operator-=(const Point& p) -> Point&;
    auto operator+(const Point& p) const -> Point;
    auto operator-(const Point& p) const -> Point;
    auto operator*(const Point& p) const -> double;
    auto operator*(double f) const -> Point;
};

auto operator*(double f, const Point& p) -> Point;
auto operator<<(ostream& os, const Point& p) -> ostream&;

#endif
