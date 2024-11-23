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
// The following definition is ok since C++17
//namespace mylibrary::onefeature {
//    double solve(int i);
//}
auto main() -> int
{
    namespace USOH = UnitedStates::OH;
    std::cout << USOH::London << "\n";
}

