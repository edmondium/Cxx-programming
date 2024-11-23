#include <array>
#include <iostream>
#include <random>

int main()
{
    std::array<unsigned, 6> freq{ 0, 0, 0, 0, 0, 0 };
    // Fill in the code needed so that we choose the
    // different sides of the die with probabilities
    // 0.3, 0.2, 0.2, 0.1, 0.1, 0.1 .
    // We select randomly by calling gen()

    for (unsigned long i = 0; i < 10'000'000; ++i)
        freq[gen()]++;
    for (unsigned f : freq)
        std::cout << f << std::endl;
}
