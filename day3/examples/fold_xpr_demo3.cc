#include <vector>
#include <iostream>
#include <algorithm>
#include <ranges>
#include <string>
#include "print_tuple.hh"

auto max_of_multiple(auto ... containers)
{
    return std::make_tuple(std::ranges::max(containers) ...);
}

auto main() -> int
{
    std::vector v1{8.2, 84., 9.1, 33.1, 9.33, 8.2, 8.3};
    std::vector v2{9,1,2,8,3,1,4,2,0,8,1};
    std::vector<std::string> v3{"Compact", "code", "with", "fold", "expressions"};
    std::cout << max_of_multiple(v1, v2, v3) << "\n";
}

