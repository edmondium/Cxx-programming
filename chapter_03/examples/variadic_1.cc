#include <iostream>
#include <string>
#if __has_include(<boost/type_index.hpp>)
#include <boost/type_index.hpp>
constexpr auto use_boost_type_index { true };
#else
#include <typeinfo>
constexpr auto use_boost_type_index { false };
#endif


// plain_type_of(var) returns the typename without reference
// symbols, const qualifiers etc.
//
template <class T>
auto plain_type_of(T&& var) -> std::string
{
    if constexpr (use_boost_type_index)
        return boost::typeindex::type_id<T>().pretty_name();
    else
        return typeid(var).name();
}

template <class... Types>
void f(Types&&... args)
{
    std::cout << "Printing out typenames without references etc. and values\n";
    ((std::cout << plain_type_of(args) << ": " << args << "\n"), ...);
}

auto main() -> int
{
    const int i { 3 }, j {};
    size_t k {}, l { 9 };
    const char* cst { "C-style string..." };
    std::string cppst { "C++ string..." };
    f(i, j, true, k, l, cst, cppst);
}

