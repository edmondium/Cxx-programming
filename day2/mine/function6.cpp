#include <iostream>
void get_lims (int &i, int &j)
{
    i = 10;
    j = 20;
}
auto main () -> int
{
    auto i = 2, j = 3;
    get_lims (i, j);
    std::cout << i << ", " << j << std::endl;
}