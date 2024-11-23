#include <iostream>

auto is_prime(unsigned int n) -> bool
{
    // recipe to tell if n is a prime or not
    return false;
}

auto main() -> int
{
    std::cout << "Number to check: ";
    unsigned int inp{};
    std::cin >> inp;
    if (is_prime(n))
        std::cout << "Yes, that's a prime.\n";
    else
        std::cout << "Not a prime.\n";
}


