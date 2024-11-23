#include <iomanip>
#include <iostream>
#include <string>
#include "Vbose.hh"

auto operator<<(std::ostream& os, const Vbose* obj) -> std::ostream&
{
    os << std::hex << (size_t)(obj);
    return os;
}

auto f(std::string a) -> Vbose
{
    std::cout << "Entering f()\n";
    Vbose tmp(a);
    if (tmp.getval() == "") {
        std::cerr << "Warning! Empty string used to construct object!\n";
    }
    std::cout << "Leaving f()\n";
    return tmp;
}

void g(Vbose v)
{
    std::cout << "Called g with " << &v << "(" << v.getval() << ")\n";
    v.setval(v.getval() + "_modified");
    std::cout << "g() : Modified v to " << v.getval() << "\n";
}

auto main() -> int
{
    std::cout << "Entering main()\n";
    std::cout << "Constructing a and b\n";
    Vbose a, b("Mercury");
    {
        Vbose c("UnusedVar");
    }
    std::cout << "Calling f and assigning result to a\n";
    a = f("Venus");

    std::cout << "Calling f without assigning the result\n";
    f("Jupitor");
    std::cout << "Statement after calling f without assigning result\n";

    std::cout << "Calling g with b\n";
    g(b);
    std::cout << "Statement after calling g with b\n";
    std::cout << "Value of b, after call to g, is " << b.getval() << "\n";

    std::cout << "Calling g with a+b\n";
    g(a + b);

    std::cout << "Calling g with std::move(a)\n";
    g(std::move(a));
    std::cout << "Leaving main()\n";
}

