#include <print>
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
    for (auto i = 0U; i < 5000000U; ++i)
        H[static_cast<int>(std::floor(generator()))]++;
    for (const auto& [i, f] : H)
        std::print("{}\t{}\n", i, f);
}
