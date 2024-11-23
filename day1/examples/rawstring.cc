#include <iostream>
#include <string>

int main()
{
    // clang-format off
    std::string s = R"xyz(This is a " raw " C++11 string.)xyz";
    std::cout << s << '\n';
    s = R"(Inside a raw string \n does not create a new line.)";
    std::cout << s << '\n';
    s = R"(The regular expression to match a sequence of up to 3 digits is \d{3})";
    // clang-format on
    std::cout << s << '\n';
}
