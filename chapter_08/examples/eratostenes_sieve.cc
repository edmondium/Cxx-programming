#include <chrono>
#include <ranges>
#include <algorithm>
#include <iostream>
#include <vector>
#include <span>
#include <cxxopts.hpp>

namespace sr = std::ranges;

template <class T>
void assign_each_nth(std::span<T> R, size_t n, T v)
{
    for (auto i = 0UL; i < R.size(); i += n)
        R[i] = v;
}

auto main(int argc, char* argv[]) -> int
{
    std::cout << "Erastothene Sieve...\n";
    using namespace std;
    using namespace std::chrono;
    auto N = 100UL;
    vector<int> candidate(N + 1, 1);
    candidate[0] = candidate[1] = 0;
    auto proc = std::span(candidate);
    auto t0 = steady_clock::now();
    for (size_t i = 2; i <= (N / 2); ++i) {
        if (candidate[i]) {
            assign_each_nth(proc.subspan(2 * i), i, 0);
        }
    }
    auto t1 = steady_clock::now();
    std::cout << "Calculating primes up to " << N << " took "
              << duration<double>(t1 - t0)<< "\n";

    std::cout << "Write primes ? (y/n): ";
    char ch;
    std::cin >> ch;
    if (ch == 'y')
        for (size_t i = 0; i < N; ++i)
            if (candidate[i])
                std::cout << i << "\n";
    std::cout << "Prime count = "
              << sr::count(candidate, 1) << "\n";
}
