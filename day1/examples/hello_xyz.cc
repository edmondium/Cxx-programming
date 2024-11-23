// examples/hello_xyz.cc
#include <iostream>
auto main(int argc, char* argv[]) -> int
{
    std::cout << "Hello, ";
    if (argc > 1)
        std::cout << argv[1] << "!\n";
    else
        std::cout << "world!\n";
}
