#include "Vbose.hh"

auto main() -> int
{

    std::cout << "Declaring lambda function {\n";
    Vbose locvar{ "dinosaur" };
    auto lambda = [=](int i) {
        std::cout << "\nIn lambda function, captured value of locvar is : "
                  << locvar.getval() << "\n";
        return i * i * i;
    };
    std::cout << "Declaring lambda function }\n";

    std::cout << "Calling lambda function {\n";
    std::cout << 5 << " -> " << lambda(5) << "\n";
    std::cout << "Calling lambda function }\n";
}
