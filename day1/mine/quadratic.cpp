#include <iostream>
#include <cmath>
auto hasRealRoots(double a, double b, double c) -> bool
{
    double discriminant { pow(b, 2) - 4 * a * c};
    return discriminant >= 0;
}
auto main() -> int
{
    double a, b, c;
    std::cout << "Enter coefficients a, b, and c: ";
    std::cin >> a >> b >> c;
    if (hasRealRoots(a, b, c)) {
        std::cout << "The quadratic equation has real roots." << std::endl;
    } else {
        std::cout << "The quadratic equation doesn't have real roots." << std::endl;
    }
}