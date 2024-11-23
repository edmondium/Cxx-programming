#include <iostream>

class A {};
class B {};

auto operator+(A x, A y) -> A
{
    std::cout << "Called operator+() with two A type arguments\n";
    return x;
}
auto operator+(B x, B y) -> B
{
    std::cout << "Called operator+() with two B type arguments\n";
    return x;
}
auto operator@(A x, B y) -> A
{
    std::cout << "Called operator+() with one A type and one B type argument\n";
    return x;
}

auto main() -> int
{
    A a1, a2;
    B b1, b2;
    a1 + a2;
    a1 @ b1;
    b1 + b2;
//    b1 + a2;
}

