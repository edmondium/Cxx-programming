#include <iostream>
#include <string>

auto the_other(int i, int j) -> int { return 3 - i - j; }

void transfer(unsigned long n, int from, int to)
{
    int oth = the_other(from, to);
    if (n > 1)
        transfer(n - 1, from, oth);
    std::cout << n << ": " << from << "->" << to << "\n";
    if (n > 1)
        transfer(n - 1, oth, to);
}

auto main() -> int
{
    size_t N = 6;
    transfer(N, 0, 1);
}
