#include <iostream>
#include <type_traits>

template < class T >
struct SomeCalc
{
  static_assert(std::is_arithmetic<T>::value,"argument T must be an arithmetic type");
  constexpr SomeCalc() {}
  constexpr auto operator()(const T & t1, const T & t2) const ->decltype(t1+t2)
  {
    return t1+t2+1; // Let's say there is a bug in the implementation 
  }
};

int main()
{
  constexpr SomeCalc<int> intadder;
  constexpr int res = intadder(1,1);
  static_assert(res==2,"Adder seems to return unexpected result");
  SomeCalc<std::string> stradder;
}


