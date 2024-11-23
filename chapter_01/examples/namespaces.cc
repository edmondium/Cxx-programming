#include <iostream>

using namespace std;

namespace UnitedKingdom {
string London = "Big city";
}
namespace UnitedStates {
string London = "Small town in Kentucky";
}
auto main() -> int
{
    using namespace UnitedKingdom;
    cout << London << "\n";
    cout << UnitedStates::London << "\n";
}
