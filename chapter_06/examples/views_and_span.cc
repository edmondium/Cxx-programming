// examples/views_and_span.cc
#include <print>
#include <span>
#include <ranges>
#include <algorithm>
#include <string>
#include <iomanip>

namespace sr = std::ranges;
namespace sv = sr::views;

auto main(int argc, char * argv[]) -> int
{
    std::span args(argv, argc);
    auto str = [](auto inp) -> std::string_view { return inp; };
    if (argc < 2) {
        std::print(R"(Usage:
{} [some strings in the command line]
)", argv[0]);
        return 1;
    }
    auto [first, last] = sr::minmax( args | sv::drop(1) | sv::transform(str) );

    std::println(R"(Alphabetically first and last strings in your input are "{}" and "{}")",
              first, last);
}

