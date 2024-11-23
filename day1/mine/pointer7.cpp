#include <iostream>
void whatisit(int* start, int* stop, int* start2)
{
    for (; start != stop; ++start, ++start2) *start2 = *start;
}
auto main() -> int
{
    int A[10]{0, 2, 1, 0, 3, 1, 1, 0, 0, 1};
    int B[10]{};
    whatisit(A, A + 10, B);
    for(int i{}; i < 10; ++i) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;
}