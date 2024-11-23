#include <iostream>
auto main() -> int
{
    int A[10]{0, 2, 1, 0, 3, 1, 1, 0, 0, 1};
    int w{};
    for (int* p{A}; p != A + 10; ++p) w += *p;
    std::cout << w << std::endl;
}