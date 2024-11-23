#include <fstream>
#include <print>
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
        std::print("{:20}   :{:12}\n",
            word, count);
}
