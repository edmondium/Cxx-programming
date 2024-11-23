#include <array>
#include <cmath>
#include <iostream>
#include <type_traits>
#include <variant>

struct pow_calc {
    double x = 0.;
    pow_calc(double xx)
        : x{ xx }
    {
    }
    void operator()(int val)
    {
        std::cout << val << " is an integer.\n";
        std::cout << "Calculating power by using the loop strategy: ";
        double ans = 1.;
        if (val > 0) {
            for (int i = 0; i < val; ++i)
                ans *= x;
        } else {
            double mul = 1.0 / x;
            for (int i = 0; i > val; --i)
                ans *= mul;
        }
        std::cout << x << "^" << val << " = " << ans << "\n";
    }
    void operator()(double val)
    {
        std::cout << val << " is a double.\n";
        std::cout << "Calculating power by using log and exp: ";
        std::cout << x << "^" << val << " = " << exp(val * log(x)) << "\n";
    }
};

auto main() -> int
{
    using namespace std;
    array<variant<int, double>, 6> powers{ 8, 9.5, 11, 12.5, 14, 15.5 };
    std::cout << "Enter a small real number (< 2.0): ";
    double x;
    std::cin >> x;

    for (auto i : powers) {
        std::visit(pow_calc{ x }, i);
    }
}
