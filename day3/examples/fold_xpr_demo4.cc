#include <vector>
#include <iostream>
#include <ranges>
#include <algorithm>
#include "range_output.hh"

auto conv(const std::vector<double>& inp, auto ... shift)
{
    namespace sr = std::ranges;
    namespace sv = std::views;
    std::vector<double> out(inp.size(), 0.);
    auto res_exp = sv::iota(0, static_cast<int>(inp.size())) 
        | sv::transform([inp, shift...](auto index){
            auto S = inp.size();
            return (inp[(index + shift) > 0 ? (index + shift) % S : S + (index + shift) % S] + ...) 
                    / (sizeof ... (shift));
        }); 

    sr::copy(res_exp, out.begin());
    return out;
}

auto main() -> int
{
    std::vector v(21UL, 0.);
    v[10] = 1.0;
    for (auto i = 0UL; i < 10; ++i) {
        v = conv(v, 0, 1, 2);
        std::cout << "After round " << i << ", v = " << output::comma_separated << v << "\n";
    }
}

