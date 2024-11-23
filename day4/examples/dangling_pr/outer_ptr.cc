#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    unsigned long* p = nullptr;
    if (argc > 1) {
        auto i = std::stoul(argv[1]);

        p = &i; 
        // Since p outlives i, storing address 
        // of i in p is a bad idea

        std::cout << "p is pointing at " << p << " storing a value " << *p << "\n";
    } else {
        std::cout << "Needs one integer command line argument!\n";
    }

    // At this point, if argc > 1, p is pointing to
    // a location where there was a variable called i
    // which has run out of scope. Accessing p here is
    // undefined behaviour.
    if (p)
        std::cout << "p is pointing at " << p << " storing a value " << *p << "\n";
}

