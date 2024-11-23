#include <ranges>
#include <print>

namespace sr = std::ranges;
namespace sv = sr::views;

auto main() -> int
{
    std::print("sv::iota with filter\n");
    for (auto i: sv::iota(-50L, 50L) 
		    | sv::filter([](long n) { return (n - 10)%7 == 0; }))
	    std::print("{}\n", i);
    std::print("sv::iota with transform\n");
    for (auto i: sv::iota(0L, 10L) | sv::transform([](long n) { return n * n; }))
        std::print("{}\n", i);
}

