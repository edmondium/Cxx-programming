// examples/hello_qa.cc
#include <string>
#include <iostream>

auto main() -> int
{
    std::string name;
    std::cout << "What's your name ? ";
    std::cin >> name;
    std::cout << "Hello, " << name << "\n";
}

