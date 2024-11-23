#include <iostream>

using namespace std;

namespace UnitedKingdom {
string London = "Big city";
}
namespace UnitedStates {
string London = "Small town in Kentucky";
}
int main()
{
    using namespace UnitedKingdom;
    cout << London << endl;
    cout << UnitedStates::London << endl;
    return 0;
}