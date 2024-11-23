// examples/strtrans.cc
#include <algorithm>
#include <iostream>
#include <string>
auto main() -> int
{
    std::string name;
    std::cout << "What's your name ? ";
    getline(std::cin, name);
    auto bkpname { name };
    std::transform(begin(name), end(name), begin(name), toupper);
    std::cout << bkpname << " <--------> " << name << "\n";
}
