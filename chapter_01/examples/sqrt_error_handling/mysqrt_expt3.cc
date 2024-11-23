#include <stdexcept>
#include <iostream>
#include <cmath>

auto mysqrt(double x) -> double
{
    const auto eps = 1.0e-12;
    const auto eps2 = eps * eps;
    if (x < 0)
        throw std::runtime_error{"Asking for square root of a negative number, are you alright?" };
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
    try {
        auto rm = mysqrt(x);
        auto rs = std::sqrt(x);
        std::cout << "Square root with own function = " << rm << "\n";
        std::cout << "Square root with standard function = " << rs << "\n";
        std::cout << "Difference = " << rm - rs << "\n";
    } catch (std::runtime_error& error) {
        std::cout << "Caught runtime_error:\"" << error.what() << "\"\n";
    }
}
