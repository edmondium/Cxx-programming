#include <iostream>
#include <string>

auto f(double x) -> double&
{
    auto y = x * x;
    return y;
}

auto main() -> int
{
    auto a = 4.0;
    auto&& z = f(a);
    std::cout << z << "\n";
}

