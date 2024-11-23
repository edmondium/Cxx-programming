#include <memory>
#include <iostream>

auto main() -> int
{
    auto u = std::make_unique<double[]>(1024);
    for (auto i = 0UL; i < 1024UL; ++i) u[i] = i;
    std::cout << u[334] << "\n";
}
