#include <iostream>
#include <string>
#include <array>
#include <algorithm>

auto main(int argc, char* argv[]) -> int
{
    std::string orig{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    auto shuf = orig;
    auto n = 5;
    do {
        std::rotate(shuf.begin(), shuf.begin() + 1, shuf.end());
        std::cout << shuf << "\n";
    } while (n-- > 0);    
}

