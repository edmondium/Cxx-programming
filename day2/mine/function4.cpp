#include <iostream>
auto f (int &x) -> int
{
    x += 1;
    return x;
}
void elsewhere ()
{
    auto z = 0;
    f ( z );
    std::cout << z << std::endl;
}
auto main () -> int
{
    elsewhere ();
}