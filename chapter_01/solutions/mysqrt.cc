#include <iostream>
#include <cmath>

auto mysqrt(double x) -> double
{
    const auto eps = 1.0e-12;
    const auto eps2 = eps * eps;
    auto r0 = 0.5 * (1. + x);
    auto r1 = x / r0;
    while ((r0 - r1) * (r0 - r1) > eps2) {
        r0 = 0.5 * (r0 + r1);
        r1 = x / r0;
    }
    return r1;
}

auto main() -> int
{
    double x{};
    std::cout << "Enter a positive real number: ";
    std::cin >> x;
    if (x > 0.) {
        auto rm = mysqrt(x);
        auto rs = std::sqrt(x);
        std::cout << "Square root with own function = " << rm << "\n";
        std::cout << "Square root with standard function = " << rs << "\n";
        std::cout << "Difference = " << rm - rs << "\n";
    } else {
        std::cout << "The input number needs to be positive.\n";
    }
}

