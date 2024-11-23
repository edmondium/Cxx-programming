#include <random>
#include <iostream>
#include <map>
auto main() -> int
{
    auto gen = [ dist = std::poisson_distribution<> {8.5}, engine = std::mt19937_64{} ]
        () mutable { return dist(engine); };
    std::map<int,unsigned> H;
    for (auto i = 0UL; i < 5000000UL; ++i) H[gen()]++;
    for (auto [i, fi] : H) std::cout << i << " " << fi << '\n';
}

