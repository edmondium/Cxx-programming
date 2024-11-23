#include <iostream>

class Temperature
{
    double v = 0.0;
    public:
    enum class Unit { K, C };
    constexpr auto ConvFrom(double x, Unit u) {
        switch (u) {
            case Unit::K : return x;
            case Unit::C : 
            default:  return 273.15 + x;
        };
    }
    Temperature() = default;
    Temperature(double x, Unit u) : v{ ConvFrom(x, u) } {}
    auto Kelvin() const noexcept -> double { return v; }
    auto Celsius() const noexcept -> double { return v; }
};
auto operator "" _K(long double d) -> Temperature
{
    return { static_cast<double>(d), Temperature::Unit::K };
}
auto operator "" _C(long double d) -> Temperature
{
    return { static_cast<double>(d), Temperature::Unit::C };
}

auto main() -> int
{
    auto T1 = 273.15_K;
    auto T2 = 100.0_C;
    std::cout << T1.Celsius() << "\t" << T2.Celsius() << "\n";
}
