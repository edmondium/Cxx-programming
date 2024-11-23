#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    std::ifstream fin(argv[1]);
    std::map<std::string, unsigned> freq;
    std::string s;

    while (fin >> s)
        freq[s]++;

    for (auto&& [word, count] : freq)
        std::cout << std::setw(12) << word
                  << std::setw(4) << ':'
                  << std::setw(12) << count
                  << "\n";
}
