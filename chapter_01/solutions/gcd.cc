#include <iostream>

auto euclid_gcd(unsigned long smaller, unsigned long larger) -> unsigned long 
{
    if (smaller > larger)
        std::swap(smaller, larger);
    while (smaller != 0) {
        auto rem = larger % smaller;
        larger = smaller;
        smaller = rem;
    }
    return larger;
}

auto main(int argc, char* argv[]) -> int 
{
    if (argc != 3) {
        std::cout << "Usage:\n"
                  << argv[0] << " number1 number2\n";
        return 1;
    }
    unsigned long n1 = std::stoul(argv[1]), n2 = std::stoul(argv[2]);
    std::cout << euclid_gcd(n1, n2) << "\n";
}
#include <iostream>

auto euclid_gcd(unsigned long smaller, unsigned long larger) -> unsigned long 
{
    if (smaller > larger)
        std::swap(smaller, larger);
    // Fill in your code to implement Euclid's algorithm here.

    return ? ? ? ;
}

auto main(int argc, char* argv[]) -> int
{
    if (argc != 3) {
        std::cout << "Usage:\n"
                  << argv[0] << " number1 number2\n";
        return 1;
    }
    unsigned long n1 = std::stoul(argv[1]), n2 = std::stoul(argv[2]);
    std::cout << euclid_gcd(n1, n2) << "\n";
}
