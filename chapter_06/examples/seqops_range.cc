#include <algorithm>
#include <print>
#include <iterator>
#include <ranges>
#include <string>
#include <vector>
using namespace std::literals;

auto main() -> int
{
    namespace sr = std::ranges;
    std::vector v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::print("Vector v = (after initialization): {}\n", v);

    std::print("The sequence is {} sorted in the increasing order.\n", 
        sr::is_sorted(v) ? ""sv : "not"sv);

    sr::reverse(v);
    std::print("After std::ranges::reverse: {}\n", v);

    sr::rotate(v, v.begin() + 3);
    std::print("After std::rotate by 3 {}\n", v);

    sr::sort(v);
    std::print("After std::ranges::sort {}\n", v);


    std::vector<int> w { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }, x, y, z;
    std::print("Vector w = {}\n", w);

    std::vector<int> m;
    sr::merge(v, w, std::back_inserter(m));
    std::print("ranges::merge of v and w gives ... : {}\n", m);

    sr::set_union(v, w, back_inserter(x));
    std::print("Union of v and w : {}\n", x);

    sr::set_intersection(w, v, back_inserter(y));
    std::print("Intersection of w and v : {}\n", y);

    sr::set_symmetric_difference(v, w, back_inserter(z));
    std::print("Symmetric difference of v and w : {}\n", z);

    std::print("The above sequence is {} a permutation of the first sequence printed.\n", 
        sr::is_permutation(z, v)? ""sv : "not"sv);
}
