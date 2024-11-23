// examples/chrono_demo.cc
#include <algorithm>
#include <chrono>
#include <cxx20ranges>
#include <iostream>
#include <vector>

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
    sr::copy(sv::iota(0UL, 10000UL) | sv::filter(is_prime), back_inserter(primes));
    std::cout << "Primes till 10000 are ... " << '\n';
    for (unsigned i : primes)
        std::cout << i << '\n';
    auto d = steady_clock::now() - t;
    std::cout << "Prime search took " << duration<double>(d).count() << " seconds\n";
}
