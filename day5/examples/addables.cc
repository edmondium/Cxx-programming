#include <iostream>
#include <string>
#include <concepts>

template <class T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
};

auto aggregate(Addable auto... args)
{
    return (args + ...);
}

auto main() -> int
{
    using namespace std::string_literals;
    std::cout << "aggregate(1, 2, 3, 4, 5) = "
              << aggregate(1, 2, 3, 4, 5) << "\n";
    std::cout << R"aw(aggregate("|-"s, "-|"s) = )aw"
                << aggregate("|-"s, "-|"s) << "\n";
}

