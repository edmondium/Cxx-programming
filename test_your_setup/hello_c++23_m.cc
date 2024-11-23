import <iostream>;
import <concepts>;

void message(auto&& x)
{
    std::print("{}\n", x);
}

template <class T>
concept is_a_number = std::integral<T> or std::floating_point<T>;

auto main() -> int
{
    message("Hello, world!");
    auto n = 1234.0;
    if constexpr (is_a_number<decltype(n)>)
	std::print("{} is a number.\n", n);
    else
	std::print("{} is not a number!\n", n);
}

