#include <iostream>
#include <string>
#include <vector>

template <typename... Args>
auto add_up(Args... args)
{
    return (args + ...);
}

template <typename T, typename... Args>
void push_back(std::vector<T> &v, Args ... args) {
    (v.push_back(args), ...);
}

auto main() -> int
{
    using namespace std;
    string firstname{ "Steve" }, lastname{ "Rogers" };
    cout << add_up(1, 2, 3, 4, 5) << "\n";
    cout << add_up(firstname, " ", lastname) << "\n";

    std::vector<double> q{0.0};
    push_back(q, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8);
    for (auto d : q) cout << d << "\n";
}
