// examples/strtrans.cc
#include <algorithm>
#include <print>
#include <iostream>
#include <string>

auto main() -> int
{
    std::string name;
    std::print("What's your name ? ");
    getline(std::cin, name);
    auto bkpname { name };
    std::transform(begin(name), end(name), begin(name), toupper);
    std::print("{} <--------> {}\n", bkpname, name);
}
