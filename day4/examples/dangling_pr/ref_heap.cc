#include <vector>
#include <iostream>

auto main() -> int
{
    std::vector v{1, 2, 3};
    const auto& vstart = v.front();
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    std::cout << "Start element of v = " << vstart << "\n";
}

