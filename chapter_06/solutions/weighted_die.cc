#include <array>
#include <iostream>
#include <random>

auto main() -> int
{
    std::array freq{ 0.3, 0.2, 0.2, 0.1, 0.1, 0.1 };
    std::mt19937_64 engine{ std::random_device{}() };
    std::discrete_distribution dist{freq.begin(), freq.end()};
    auto gen = [&]{ return dist(engine); };
    for (unsigned long i = 0; i < 10'000'000; ++i)
        freq[gen()]++;
    for (unsigned f : freq)
        std::cout << f << std::endl;
}
