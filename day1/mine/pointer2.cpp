#include <iostream>
auto main() -> int
{
    int A[10]{0, 2, 1, 0, 3, 1, 1, 0, 0, 1};
    int w{};
    for (int i = 0; i < 10; ++i) w += *(A+i);
    std::cout << w << std::endl;
}