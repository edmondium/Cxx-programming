#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include <ranges>
#include <algorithm>

namespace fs = std::filesystem;
auto as_lines(fs::path file) -> std::vector<std::string>
{
    std::ifstream fin{ file };
    std::string line;
    std::vector<std::string> lines;
    while (getline(fin, line)) lines.push_back(line);
    return lines;
}

auto main(int argc, char* argv[]) -> int
{
    if (argc != 2) {
        std::cerr << "Usage:\n"
                  << argv[0] << " filename\n";
        return 1;
    }
    auto content = as_lines(argv[1]);
    std::ranges::sort(content,
                 [](auto l1, auto l2) {
                     return std::stod(l1) < std::stod(l2);
                 }
             );
    for (std::string_view line : content) {
        std::cout << line << "\n";
    }
}

