#include <iostream>

auto is_prime(unsigned int n) -> bool
{
    bool found_divisor = false;
    for (auto i = 2U; 
         (not found_divisor) and i * i <= n;
         ++i) {
        if (n % i == 0U) found_divisor = true;
    }
    return (not found_divisor);
}

auto main() -> int
{
    std::cout << "Number to check: ";
    unsigned int inp{};
    std::cin >> inp;
    if (is_prime(inp))
        std::cout << "Yes, that's a prime.\n";
    else
        std::cout << "Not a prime.\n";
}


