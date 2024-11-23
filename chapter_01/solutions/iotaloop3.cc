#include <print>
#include <ranges>

namespace sr = std::ranges;
namespace sv = sr::views;
auto my_selection(int i) -> bool
{
    return (i - 10) % 7 == 0;
}
auto main() -> int
{
    for (auto i : sv::iota(-50, 50) | sv::filter(my_selection))
        std::print("{}\n", i);
}


