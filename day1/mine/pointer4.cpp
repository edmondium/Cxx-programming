#include <iostream>
auto main() -> int
{
    int A[10]{0, 2, 1, 0, 3, 1, 1, 0, 0, 1};
    int w{};
    int* start{A};
    int* stop{A + 10};
    for (int* p{start}; p != stop; ++p) {
        w += *p;
    }
    std::cout << w << std::endl;
}