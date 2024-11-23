#include <iostream>
#include <stdexcept>
unsigned long euclid_gcd(unsigned long smaller, unsigned long larger)
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

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cout << "Usage:\n"
                  << argv[0] << " number1 number2\n";
        return 1;
    }
    try {
        unsigned long n1 = std::stoul(argv[1]), n2 = std::stoul(argv[2]);
        std::cout << euclid_gcd(n1, n2) << "\n";
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: Invalid input. Please enter two valid numbers." << std::endl;
        return 1;
    } catch (const std::out_of_range &e) {
        std::cerr << "Error: One or both numbers are out of range." << std::endl;
        return 1;
    }
    return 0;
}
