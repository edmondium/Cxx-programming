#include <iostream>
#include <string>
#include <variant>

auto main() -> int
{
    std::variant<long, double> V{ 0.55 };
    if (auto lptr = std::get_if<long>(&V)) {
        std::cout << "Stores a long, value = " << *lptr << "\n";
    } else if (auto dptr = std::get_if<double>(&V)) {
        std::cout << "Stores a double, value = " << *dptr << "\n";
    } else
        std::cerr << "If you see this, someone forgot to handle "
                  << "all possible alternatives in the variant!\n";
}
