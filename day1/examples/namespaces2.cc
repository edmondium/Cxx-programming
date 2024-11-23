#include <iostream>
namespace UnitedKingdom {
std::string London = "Big city";
}
namespace UnitedStates {
namespace KY {
    std::string London = "Small town in Kentucky";
}
namespace OH {
    std::string London = "Small town in Ohio";
}
}
// The following definition is ok in C++17
//namespace mylibrary::onefeature {
//    double solve(int i);
//}
int main()
{
    namespace USOH = UnitedStates::OH;
    std::cout << USOH::London << std::endl;
    return 0;
}
