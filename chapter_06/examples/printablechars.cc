#include <algorithm>
#include <cctype>
#include <print>
#include <ranges>
#include <vector>

namespace sr = std::ranges;
namespace sv = sr::views;

auto main() -> int
{
    auto printable = [](auto i) { return std::isprint(i); };
    std::println("{::c}", sv::iota(0U, 256U) | sv::filter(printable));
}
