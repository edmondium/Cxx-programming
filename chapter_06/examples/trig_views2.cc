#include <print>
#include <ranges>
#include <algorithm>
#include <cmath>
#include <limits>

auto main() -> int
{
    namespace sr = std::ranges;
    namespace sv = sr::views;
    const auto pi = std::acos(-1);
    constexpr auto npoints = 100UL;
    auto is_bad = [=](double x){ return x > 0; };
    auto res = sv::iota(0UL, npoints)
               | sv::transform([=](auto idx){ 
                                   auto output =  std::lerp(0., 2*pi, idx * 1.0 / npoints);
                                   std::print("Mapping {} to {}\n", idx, output);
                                   return output;
                               } )
               | sv::transform([ ](auto x)  { 
                                   auto output = sin(x) * sin(x) - 0.99;
                                   std::print("Input = {}\toutput = {}\n", x, output); 
                                   return output;
                               } );
    std::print("Evaluating any_of ...\n");
    if (sr::any_of(res, is_bad) ) {
        std::print(stderr, "There is at least one input for which the relation does not hold.\n");
    } else {
        std::print(stderr, "The relation holds for all inputs\n");
    }
}


