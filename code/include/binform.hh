#include <array>
#include <bit>
#include <iostream>
#include <bitset>
#include <cstddef>
#include <concepts>
#include <iomanip>
#include <print>

namespace cxx_course {
template <class T>
concept Number = std::floating_point<T> || std::integral<T>;

template <Number T>
auto bits(const T& var)
{
    auto bytes = std::bit_cast<std::array<unsigned char, sizeof(T)>>(var);
    std::bitset<sizeof(T) * 8UL> ans{};
    for (unsigned i = 0U; i < bytes.size(); ++i) {
        auto b = bytes[i];
	for (unsigned j = 0U; j < 8U; ++j) {
            if (b & (static_cast<unsigned char>(1) << j)) ans.set(8U * i + j);
	}
    }
    return ans;
}

void showbits(double var)
{
    std::print("bits for double value {}\n", var);
    auto b = bits(var).to_string();
    std::print("raw = {}\n", b);
    std::print("sign  exponent          mantissa\n");
    std::print("{: <6}{: <16}  {}\n\n",  b[0], b.substr(1UL, 11), b.substr(12));
}

void showbits(float var)
{
    std::print("bits for float value {}\n", var);
    auto b = bits(var).to_string();
    std::print("raw = {}\n", b);
    std::print("sign  exponent          mantissa\n");
    std::print("{: <6}{: <16}  {}\n\n",  b[0], b.substr(1UL, 8), b.substr(9));
}

void showbits(auto var)
{
    std::print("bits for {} with non-floating point type : {}\n", var, bits(var).to_string());
}

}

