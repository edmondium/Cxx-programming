#include "Vbose.hh"

void testfunc(int i)
{
    std::cout << "Entering testfunc with argument " << i << "\n";
    Vbose v{"VFROMTESTFUNC"};
    if (i > 2) {
        std::cout << "Exiting testfunc() via exception.\n";
        throw 2;
    }
    else std::cout << "Passed check point 2\n";
    std::cout << "Last line of testfunc("<< i << ")\n"; 
}

auto main() -> int
{
    try {
    testfunc(0);
    testfunc(1);
    testfunc(3);
    testfunc(2);
    } catch (int err) {
        std::cout << "Caught exception " << err << "\n";
    }
}
