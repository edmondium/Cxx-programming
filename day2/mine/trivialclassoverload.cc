#include <iostream>
class A{};
class B{};

void f(int i, A a)
{
    std::cout << "Called version with input types (int, A)\n";
}
void f(int i, B b)
{
    std::cout << "Called version with input types (int, B)\n";
}
auto main() -> int
{
    A xa;
    B xb;
    f(0, xa);
    f(0, xb);
}
