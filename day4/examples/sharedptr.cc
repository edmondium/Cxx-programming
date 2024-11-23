#include <iostream>
#include <memory>

struct MyStruct {
    int vl{ 0 };

    MyStruct(int i)
        : vl{ i }
    {
        std::cout << "Creating MyStruct at memory address " 
                  << (void*)this << " with data " << vl << "\n";
    }
    ~MyStruct()
    {
        std::cout << "Destroying MyStruct at memory address " 
                  << (void*)this << " with data " << vl << "\n";
    }
    MyStruct()
        : MyStruct(0)
    {
    }
};

auto main() -> int
{
    auto u1 = std::make_shared<MyStruct>(1);
    auto u2 = u1; //ok
    auto u3 = std::move(u1);
    std::cout << "Data value for u3 is u3->vl = " << u3->vl << "\n";
    std::cout << "Reference count of u1 is " << u1.use_count() << "\n";
    std::cout << "Reference count of u2 is " << u2.use_count() << "\n";
    std::cout << "Reference count of u3 is " << u3.use_count() << "\n";
}
