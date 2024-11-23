#include <iostream>
#include <string>
#include <tuple>

template <int idx, int MAX, typename... Args>
struct PRINT_TUPLE {
    static void print(std::ostream& strm, const std::tuple<Args...>& t)
    {
        if
            constexpr(idx < MAX)
            {
                strm << std::get<idx>(t);
                if
                    constexpr((idx + 1) < MAX) strm << ", ";
                PRINT_TUPLE<idx + 1, MAX, Args...>::print(strm, t);
            }
    }
};

template <typename... Args>
auto operator<<(std::ostream& strm, const std::tuple<Args...>& t) -> std::ostream&
{
    strm << "[";
    PRINT_TUPLE<0, sizeof...(Args), Args...>::print(strm, t);
    return strm << "]";
}

auto main() -> int
{
    std::tuple<int, std::string, double, int, double> t{ 23, "abc", 3.141, 3, 2.718 };
    std::cout << t << "\n";
}
