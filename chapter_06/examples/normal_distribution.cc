#include <iostream>
#include <map>
#include <random>

auto main() -> int
{
    // write code here so that the callable variable
    // of name generator gives you a new pseudo-random 
    // number distributed as a gaussian or
    // normal distribution
    // auto generator = ?
    std::map<int, unsigned> H;
    for (unsigned i = 0; i < 5000000; ++i)
        H[static_cast<int>(std::floor(generator()))]++;
    for (auto& i : H)
        std::cout << i.first << " " << i.second << "\n";
}
