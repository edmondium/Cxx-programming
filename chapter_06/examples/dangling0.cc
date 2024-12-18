#include <string>
#include <ranges>
#include <algorithm>
#include <iostream>
#include <vector>

namespace sr = std::ranges;
namespace sv = sr::views;

auto get_vec()
{
    std::vector v{ 2, 4, -1, 8, 0, 9 };
    return v;
}

auto main() -> int
{
    auto vec = get_vec();
    auto iter = sr::min_element(get_vec());
    std::cout << "Minimum value is " << *iter << "\n";
}

