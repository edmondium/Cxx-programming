// examples/chrono_demo.cc
#include <algorithm>
#include <chrono>
#include <ranges>
#include <iostream>
#include <vector>

namespace sr = std::ranges;
namespace sv = sr::views;

constexpr auto is_prime_rec(size_t number, size_t c) -> bool
{
    return (c * c > number) ? true : (number % c == 0) ? false
                                                       : is_prime_rec(number, c + 1);
}
constexpr auto is_prime(size_t number) -> bool
{
    return (number <= 1) ? false : is_prime_rec(number, 2);
}

auto main() -> int
{
    using namespace std::chrono;
    std::vector<unsigned> primes;
    auto t = steady_clock::now();
    sr::copy(sv::iota(0UL, 50000UL) | sv::filter(is_prime), back_inserter(primes));
    std::cout << "Primes till 50000 are ... " << '\n';
    for (unsigned i : primes)
        std::cout << i << '\n';
    auto d = steady_clock::now() - t;
    std::print("Prime search took {}\n", duration<double>(d));
}
