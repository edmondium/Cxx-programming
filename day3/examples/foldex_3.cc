// examples/foldex_3.cc
#include <algorithm>
template <class First, class... Args>
auto min(First first, Args... args)
{
    First retval = first;
    ((retval = std::min(retval, args)), ...);
    return retval;
}
int main()
{
    return min(8, 3, 4, 7, 2, 7) + min(2, 3, 9, 1);
}
