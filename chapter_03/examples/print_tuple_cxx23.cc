#include <print>
#include <tuple>
#include <string_view>

auto main() -> int
{
    using namespace std::literals;
    std::tuple t{0.1, 11, "eleven hundred"sv};
    std::print("{}\n", t);
}

