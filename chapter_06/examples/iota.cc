// examples/iota.cc
#include <iostream>
#include <ranges>
// Compatibility header.

auto main() -> int
{
    namespace sr = std::ranges;
    namespace sv = sr::views;
    // Uncomment the line above if not using
    // the compatibility header.
    for (auto i : sv::iota(1UL)) {
        if ((i + 1) % 10000UL == 0UL) {
            std::cout << i << ' ';
            if ((i + 1) % 100000UL == 0UL)
                std::cout << '\n';
            if (i >= 100000000UL)
                break;
        }
    }
}
