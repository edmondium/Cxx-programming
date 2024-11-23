// examples/min_of_three.cc
#include <iostream>

auto min_of_three(int a, int b, int c) -> int
{
    if (a <= b) {
        if (a <= c) return a;
        else return c;
    } else {
        if (b <= c) return b;
        else return c;
    }
}
auto main() -> int
{
    int i = 0, j = 0, k = 0;
    std::cout << "Enter i, j and k: ";
    std::cin >> i >> j >> k;
    std::cout << "The smallest of the three is " << min_of_three(i, j, k) << "\n";
}

