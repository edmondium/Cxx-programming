#include <iostream>
#include <cmath>
#include <optional>

auto mysqrt(double x) -> std::optional<double>
{
    std::optional<double> ans;
    const auto eps = 1.0e-12;
    const auto eps2 = eps * eps;
    if (x >= 0.) {
    auto r0 = 0.5 * (1. + x);
    auto r1 = x / r0;
    while ((r0 - r1) * (r0 - r1) > eps2) {
        r0 = 0.5 * (r0 + r1);
        r1 = x / r0;
    }
        ans = r1;
    }
    return ans;
}

auto main() -> int
{
    double x{};
    std::cout << "Enter a positive real number: ";
    std::cin >> x;
    if (auto rm = mysqrt(x); rm) {
        auto rs = std::sqrt(x);
        std::cout << "Square root with own function = " << rm.value() << "\n";
        std::cout << "Square root with standard function = " << rs << "\n";
        std::cout << "Difference = " << rm.value() - rs << "\n";
    } else {
        std::cout << "Square root does not contain a value. Bad input!\n";
    }
}

