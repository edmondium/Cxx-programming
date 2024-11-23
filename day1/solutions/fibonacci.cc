#include <iostream>
#include <limits>

auto main() -> int
{
    size_t umax{ std::numeric_limits<size_t>::max() };
    unsigned nfib = 0;
    size_t f0{ 0 }, f1{ 1 };
    do {
        size_t f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
        ++nfib;
    } while (f1 < umax - f0);
    std::cout << "The largest number in the Fibonacci sequence under " << umax << " is " << f1 << "\n";
    std::cout << "Number of entries in the Fibonacci sequence under " << umax << " is " << nfib << "\n";
}
