#include <print>
#include <ranges>
#include <algorithm>
#include <vector>
#include <string>

namespace sr = std::ranges;
namespace sv = sr::views;

auto main() -> int
{
    std::string s{R"(  __                            _          # /__)_   _ _ _ _  _  '  _  '   / ) _|_  _|_#/   / ()(// (///)//)//)(/ //) (__   |    | #       _/             _/                   #)"};

    for (auto v : sv::split(s, '#'))
        std::print("{}\n", std::string_view(v));
}

