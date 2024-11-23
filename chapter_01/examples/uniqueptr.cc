#include <iostream>
#include <memory>

struct MyStruct {
    MyStruct(int i)
        : vl{ i }
    {
        std::cout << "Creating MyStruct at memory address "
                  << static_cast<void*>(this) << " with data " << vl << "\n";
    }
    ~MyStruct()
    {
        std::cout << "Destroying MyStruct at memory address "
                  << static_cast<void*>(this) << " with data " << vl << "\n";
    }
    int vl = 0;
    MyStruct()
        : MyStruct(0)
    {
    }
};

auto main() -> int
{
    auto u1 = std::make_unique<MyStruct>(1);
    // The integer passed as argument is forwarded to the constructor of MyStruct
    //    auto u2 = u1; //won't compile
    auto u3 = std::move(u1);
    std::cout << "Data value for u3 is u3->vl = " << u3->vl << "\n";
    auto u4 = std::make_unique<MyStruct[]>(4);
    // When we want to create an array with make_unique, we have to express
    // this wish through the template parameter to make_unique. Here we see
    // that u4 becomes an array, even if we are simply passing one integer
    // as an argument, like we did for u1.
}
