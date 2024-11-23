#include <array>
#include <iostream>
#include <list>
#include <numeric>

template <class... Types>
void increment_all(Types&... args) { (++args, ...); }
template <class... Ts>
void h(Ts... args)
{
    std::cout << "Printing parameters passed to h \n";
    ((std::cout << args << "\t"), ...);
    std::cout << "\n";
    [=, &args...] { return increment_all(args...); }();

    std::cout << "\nModified value due to call to increment_all() through lambda \n";
    ((std::cout << args << "\t"), ...);
    std::cout << "\n";

    std::cout << "Creating std::array out of parameters...\n";
    std::array t { args... };

    std::cout << "\nsum = " << std::reduce(t.begin(), t.end()) << "\n";
}
auto main() -> int
{
    int i = 0;
    std::list l { 0, 2, 4, 8, 16 };
    auto it = l.begin();
    std::cout << "i = " << i << "; iterator it points to list element of value " << (*it) << "\n";
    std::cout << "increment_all(i, it)\n";
    increment_all(i, it);
    std::cout << "i = " << i << "; iterator it points to list element of value " << (*it) << "\n";
    std::cout << "Calling h(1, 2, 3, 4)\n";
    h(1, 2, 3, 4);
}
