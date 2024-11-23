#include <iostream>
#include <string>
#include <tuple>

template <int idx, int MAX, typename... Args>
struct PRINT_TUPLE {
    static void print(std::ostream& strm, const std::tuple<Args...>& t)
    {
        strm << std::get<idx>(t) << (idx + 1 == MAX ? "" : ", ");
        PRINT_TUPLE<idx + 1, MAX, Args...>::print(strm, t);
    }
};

template <int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...> {
    static void print(std::ostream& strm, const std::tuple<Args...>& t)
    {
    }
};

template <typename... Args>
std::ostream& operator<<(std::ostream& strm, const std::tuple<Args...>& t)
{
    strm << "[";
    PRINT_TUPLE<0, sizeof...(Args), Args...>::print(strm, t);
    return strm << "]";
}

//int main()
//{
//    std::tuple<int, std::string, double, int, double > t{23,"abc",3.141, 3, 2.718};
//    std::cout << t << "\n";
//}
