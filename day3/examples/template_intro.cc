#include <iostream>

template <class T>
void copy(T* start, T* end, T* start2)
{
    for (; start != end; ++start, ++start2) {
        *start2 = *start;
    }
}

auto main() -> int
{
    double x[10], y[10];
    for (auto& num : x)
        num = 1;
    copy(x, x + 10, y);
    for (auto&& num : y)
        std::cout << num << "\n";

    std::string anames[5] = { "a", "b", "c", "d", "e" };
    std::string bnames[5] = { " ", " ", " ", " ", " " };

    copy(anames, anames + 5, bnames);
    for (auto&& name : bnames)
        std::cout << name << "\n";
}
