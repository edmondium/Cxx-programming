#include <array>
#include <iostream>
#include <iomanip>
#include <format>
#include <ctre.hpp>

class Distance {
public:
    enum class unit : unsigned { metre = 0U,
        kilometre = 1U,
        centimetre = 2U };

private:
    static constexpr auto index(unit u) -> unsigned
    {
        return static_cast<unsigned>(u);
    }
    // The conv array has the factors you need to divide
    // by to convert a value in a given unit to the
    // internal representation, which is always in metres
    static constexpr std::array conv { 1.0, 1.0e-3, 100.0 };
    double val {}; // internal, always in metres
public:
    Distance() = default;
    Distance(const Distance&) = default;
    Distance(Distance&&) noexcept = default;
    auto operator=(const Distance&) -> Distance& = default;
    auto operator=(Distance&&) noexcept -> Distance& = default;
    Distance(double v, unit u)
        : val { v / conv[index(u)] }
    {
    }
    auto value(unit in_unit) const noexcept { return val * conv[index(in_unit)]; }
    void value(double v, unit u) { val = v / conv[index(u)]; }
    void str(std::string_view sv);
};

auto operator""_m(long double inp) -> Distance { return { static_cast<double>(inp), Distance::unit::metre }; }
auto operator""_km(long double inp) -> Distance { return { static_cast<double>(inp), Distance::unit::kilometre }; }
auto operator""_cm(long double inp) -> Distance { return { static_cast<double>(inp), Distance::unit::centimetre }; }

auto operator<<(std::ostream& os, const Distance& d) -> std::ostream&
{
    os << d.value(Distance::unit::metre) << "_m";
    return os;
}

auto operator>>(std::istream& is, Distance& d) -> std::istream&
{
    std::string val;
    is >> std::quoted(val);
    d.str(val);
    return is;
}

auto main() -> int
{
    Distance d { 4.0, Distance::unit::kilometre };
    std::cout << d << "\n";
    Distance c { 35.4_cm };
    std::cout << c << "\n";
    std::cout << "Enter distance: ";
    std::cin >> d;
    std::cout << "That's " << d << "\n";
}

void Distance::str(std::string_view diststr)
{
    static constexpr ctll::fixed_string trx {
        R"(^(-?[0-9]*\.?[0-9]+)(_|[ ]*)(m|metre|metres|cm|centimetre|centimetres|km|kilometre|kilometres)$)"
    };
    if (auto m = ctre::match<trx>(diststr); m) {
        auto numstr = m.get<1>().to_string();
        auto num = std::stod(numstr);
        auto ustr = m.get<3>().to_view();
        if (ustr == "m" or ustr == "metre" or ustr == "metres") {
            value(num, unit::metre);
        } else if (ustr == "cm" or ustr == "centimetre" or ustr == "centimetres") {
            value(num, unit::centimetre);
        } else if (ustr == "km" or ustr == "kilometre" or ustr == "kilometres") {
            value(num, unit::kilometre);
        }
    } else {
        throw std::runtime_error(format(R"(Bad value "{}" for distance!)", diststr));
    }
}

