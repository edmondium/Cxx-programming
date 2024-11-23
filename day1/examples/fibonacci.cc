#include <iostream>
#include <limits>

int main()
{
    size_t umax{ std::numeric_limits<size_t>::max() };
    unsigned nfib = 0;
    size_t f0{ 0 }, f1{ 1 };
    // Insert your code here
    std::cout << "The largest number in the Fibonacci sequence under " << umax << " is " << f1 << "\n";
    std::cout << "Number of entries in the Fibonacci sequence under " << umax << " is " << nfib << "\n";
}
