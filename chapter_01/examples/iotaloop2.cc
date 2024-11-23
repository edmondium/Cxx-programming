#include <print>
#include <ranges>

namespace sr = std::ranges;
namespace sv = sr::views;
auto divisible_by_4(int i) -> bool
{
    return i % 4 == 0;
}
auto main() -> int
{
    for (auto i : sv::iota(1, 500) | sv::filter(divisible_by_4))
        std::print("{}\n", i);
}


