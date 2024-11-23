#include <iostream>
auto whatisit(int* start, int* stop) -> int
{
    int w{};
    for (; start != stop; ++start) w += *start;
    return w;
}
auto main() -> int
{
    int A[10]{0, 2, 1, 0, 3, 1, 1, 0, 0, 1};
    int sum { whatisit(A, A + 10)};
    std::cout << sum << std::endl;
}