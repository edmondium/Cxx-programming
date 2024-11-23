// examples/midpt.cc
#include <iostream>

auto mid(int a, int b) -> int
{
    return (a + b) / 2;
}
auto main() -> int
{
    int i = 0, j = 0;
    std::cout << "Enter i, j: ";
    std::cin >> i >> j;
    std::cout << "A number half way between " << i << " and " << j
              << " is " << mid(i, j) << "\n";
}

