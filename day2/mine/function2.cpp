#include <iostream>
auto main () -> int
{
    int x { 1 };
    int &y { x };
    y += 1;
    std::cout << x << std::endl;
}