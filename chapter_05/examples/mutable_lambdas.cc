#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

auto main() -> int
{
    using namespace std;
    vector<unsigned long> v, w;
    generate_n(back_inserter(v), 100, [i = 0UL]() mutable {
        ++i;
        return i * i;
    });
    // v = [1, 4, 9, 16 ... ]
    std::cout << " v = \n";
    for (auto el : v)
        std::cout << el << "\n";
    generate_n(back_inserter(w), 50, [ i = 0UL, j = 1UL ]() mutable {
        i = std::exchange(j, j + i);
        return i;
    });
    // w = [1, 1, 2, 3, 5, 8, 11 ...]

    std::cout << " w = \n";
    for (auto&& el : w)
        std::cout << el << "\n";
}

