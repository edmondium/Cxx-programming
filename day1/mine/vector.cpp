#include <vector>
#include <iostream>
auto main () -> int
{
    const std::vector v {1, 2, 3, 4, 5};
    auto tot {0};
    for (const auto el : v) tot += el;
    std::cout << tot << std::endl;
}