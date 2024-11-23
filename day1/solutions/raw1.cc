#include <iostream>
#include <string>

auto main() -> int
{
    using namespace std;
    cout << "Use a single backslash character at the end of the line to continue input to the next line, as shown ...\n"
         << R"(OBJ=a.o \
	b.o\
	c.o
)";
}
