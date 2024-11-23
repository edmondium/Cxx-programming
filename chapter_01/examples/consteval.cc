#include <algorithm>
#include <ranges>
namespace sr = std::ranges;
namespace sv = sr::views;

consteval auto is_prime(unsigned N) -> bool
{
    return sr::none_of(
        sv::iota(2U) 
          | sv::take_while([=](auto i) { return i * i <= N; }),
        [=](auto i){ return N % i == 0; });
}

auto main() -> int
{
    return (sr::fold_left(
        sv::iota(2U)
          | sv::filter([](unsigned i) { return is_prime(i); })
          | sv::take(10U),
        0UL, 
        std::plus<unsigned long>{}));
}

