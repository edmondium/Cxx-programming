#include <iostream>

unsigned long euclid_gcd(unsigned long smaller, unsigned long larger)
{
    if (smaller > larger)
        std::swap(smaller, larger);
    // Fill in your code to implement Euclid's algorithm here.
    while (smaller != 0) {
        auto remainder = larger % smaller;
        larger = smaller;
        smaller = remainder;
    }
    return larger;
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cout << "Usage:\n"
                  << argv[0] << " number1 number2\n";
        return 1;
    }
    unsigned long n1 = std::stoul(argv[1]), n2 = std::stoul(argv[2]);
    std::cout << euclid_gcd(n1, n2) << "\n";
}
