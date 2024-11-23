#include "binform17.hh"
#include <iostream>

template <class T>
void handle()
{
    std::cout << "Enter value: ";
    T v;
    std::cin >> v;
    cxx_course::showbits(v);
}

auto main() -> int
{
    bool keeplooping{true};
    while (keeplooping) {
        int ch{};
        std::cout << "Select type (1: int, 2: unsigned int, 3: long, 4: unsigned long, 5: float, 6: double): ";
        std::cin >> ch;
        switch (ch) {
        case 1: 
            handle<int>(); break;
        case 2: 
            handle<unsigned int>(); break;
        case 3: 
            handle<long>(); break;
        case 4: 
            handle<unsigned long>(); break;
        case 5: 
            handle<float>(); break;
        case 6: 
            handle<double>(); break;
        case 0: keeplooping = false; break;
        default:;
        };
    }
}

