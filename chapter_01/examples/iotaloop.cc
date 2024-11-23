#include <print>
#include <ranges>

namespace sr = std::ranges;
namespace sv = sr::views;

auto main() -> int
{
    for (auto i : sv::iota(10, 15)) std::print("{}\n", i);
}


