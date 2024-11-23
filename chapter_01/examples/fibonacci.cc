#include <iostream>
#include <limits>
#include <format>

auto main() -> int
{
    using namespace std;
    size_t umax{ numeric_limits<size_t>::max() };
    unsigned nfib = 0;
    size_t f0{ 0 }, f1{ 1 };
    // Insert your code here

    cout << format(R"(The largest number in the Fibonacci sequence under {0:} is {1:},
and there are {2:} entries under {0:} in that sequence.
)"                 , umax, f1, nfib);
}
