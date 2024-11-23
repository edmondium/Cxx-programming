#include <array>
#include <iostream>
#include <list>
#include <numeric>
#include <concepts>

template <class T>
concept Incrementable = requires(T ex) {
    { ++ex };
};

template <Incrementable... Types>
void increment_all(Types&... args) { (++args, ...); }

// For function h() below, we can have as many parameters as
// we want, but those parameters should all be of the same type.
// To express this requirement, we create a variable template
// AllSame_v<T...> which has a value true if all its template
// parameters are true.
//
template <class... Ts>
constexpr bool AllSame_v = true; // general template
template <class First, class Second, class... Rest> 
constexpr bool AllSame_v<First, Second, Rest...> // specialization
    = std::is_same_v<First, Second> && AllSame_v<Second, Rest...>;

// Now the concept AllSame can be expressed as follows
template <class... Ts> concept AllSame = AllSame_v<Ts...>;

template <class... Ts>
void h(Ts&&... args) requires AllSame<Ts...>
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
    h(1, 2, 3, 4); // No problems!
    // h(1, 2, 3, 4.); // Problems!
    // h(i, 2, 3, 4); // Problems!
    int j = 0;
    h(i, j); // No problems!
    const int k{7};
    std::cout << "Introducing a constant integer k = " << k << "\n";
    // h(k, k); // Problems!
    // h(i, j, k); // Problems!
}
