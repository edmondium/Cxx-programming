#include <tuple>
#include <iostream>
#include <iomanip>

template <class ... Args>
auto operator<<(std::ostream & strm, const std::tuple<Args...> & t) -> std::ostream & 
{
    using namespace std;
    auto print_one = [&strm](const auto & onearg) -> ostream & {
        using bare_type = remove_cv_t<remove_reference_t<decltype(onearg)>>;
        if constexpr (is_same_v<bare_type, string>)
            strm << quoted(onearg);
        else
            strm << onearg;
        return strm;
    };
    auto print_components = [&](const auto & ... args){
       ((print_one(args) << ", "), ...);
    };
    strm << "[";
    apply(print_components, t);
    return strm <<"]";
}

auto main() -> int
{
    std::tuple t1{1, "one"};
    std::tuple t2{2, "two", "II", 2.0};
    std::cout << t1 << "\t" << t2 << "\n";
}

