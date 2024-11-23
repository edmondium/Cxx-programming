// examples/min_of_three.cc
#include <iostream>

auto min_of_three(int a, int b, int c) -> int
{
    // recipe needed!
    return a;
}
auto main() -> int
{
    int i = 0, j = 0, k = 0;
    std::cout << "Enter i, j and k: ";
    std::cin >> i >> j >> k;
    std::cout << "The smallest of the three is " << min_of_three(i, j, k) << "\n";
}

