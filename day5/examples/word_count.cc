#include <fstream>
#include <cxx20format>
#include <cxx20ranges>
#include <iostream>
#include <map>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    std::ifstream fin(argv[1]);
    std::map<std::string, unsigned> freq;
    std::string s;
    auto non_alphabetic = [](auto c) { return not isalpha(c); };

    while (fin >> s) {
        std::string s2;
        sr::copy(s | sv::drop_while(non_alphabetic)
                   | sv::reverse
                   | sv::drop_while(non_alphabetic)
                   | sv::reverse, std::back_inserter(s2));
        freq[s2]++;
    }

    for (auto&& [word, count] : freq)
        std::cout << fmt::format("{:20}{:4}{:12}\n", word, ':', count);
}
