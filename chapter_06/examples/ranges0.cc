#include <print>
#include <span>
#include <vector>
#include <valarray>
#include <list>
#include <array>
#include <string>
#include <ranges>

namespace sr = std::ranges;
namespace sv = sr::views;

auto sum(sr::input_range auto&& seq)
{
    std::iter_value_t<decltype(seq)> ans{};
    for (auto&& x : seq) ans += x;
    return ans;
}

auto main() -> int
{
    using namespace std::string_literals;
    std::print("vector : {}\n", sum(std::vector({ 9,8,7,2 } )));
    std::print("list : {}\n", sum(std::list({ 9,8,7,2 } )));
    std::print("valarray : {}\n", sum(std::valarray({ 9,8,7,2 } )));
    std::print("array : {}\n", sum(std::array<int,4>({ 9,8,7,2 } )));
    std::print("array : {}\n", sum(std::array<std::string, 4>({ "9"s,"8"s,"7"s,"2"s } )));
    int A[]{1,2,3};
    std::print("C-array wrapped by span : {}\n", sum(std::span(A)));
}

