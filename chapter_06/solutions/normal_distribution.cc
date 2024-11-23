#include <iostream>
#include <print>
#include <map>
#include <random>

auto main() -> int
{
    double mn{0.}, var{1.};
    std::cout << "Mean : ";
    std::cin >> mn;
    std::cout << "Variance: ";
    std::cin >> var;

    std::mt19937_64 engine{ std::random_device{}() };
    // Above: First create an object of the type std::random_device.
    // random_device objects can be called like functions.
    // They give you non-deterministic random numbers, but
    // not necessarily of the best mathematical quality.
    // We create the object, and immediately call it:
    // which is why we have the () after the empty initialiser
    // braces {}. This gives us a random unsigned long
    // integer, which we then use to seed the Mersenne Twister
    // engine.
    std::normal_distribution<> dist{mn, std::sqrt(var) };
    auto generator = [&]{ return dist(engine); };

    std::map<int, unsigned> H;
    for (auto i = 0U; i < 5000000U; ++i)
        H[static_cast<int>(std::floor(generator()))]++;
    for (const auto& [i, f] : H)
        std::print("{}\t{}\n", i, f);
}
