#include <iostream>

class complex_number
{
public:
    // If the constructor is meant to do nothing, let the compiler generate it
    constexpr complex_number() noexcept = default;
    // Same for the destructor
    ~complex_number() noexcept = default;
    // Constructor with real and imaginary parts
    constexpr complex_number(double re, double im) noexcept;
    // Constructor with only a real part. It "delegates" its work to the 
    // constructor above. See its implementation below
    constexpr complex_number(double re) noexcept;
    // Copy constructor with trivial member wise copy
    constexpr complex_number(const complex_number &c) noexcept = default;
    // Trivial assignment operator
    constexpr auto operator=(const complex_number& c) noexcept -> complex_number& = default;
    // Move constructor with trivial member wise move
    constexpr complex_number(complex_number &&c) noexcept = default;
    // Move assignment operator
    constexpr auto operator=(complex_number&& c) noexcept -> complex_number& = default;
    // Arithmetic operators changing the calling object
    constexpr auto operator+=(const complex_number&) noexcept -> complex_number&;
    constexpr auto operator-=(const complex_number&) noexcept -> complex_number&;
    constexpr auto operator*=(const complex_number&) noexcept -> complex_number&;
    // Accessor functions
    constexpr auto real() const noexcept -> double { return m_real; }
    constexpr auto imag() const noexcept -> double { return m_imag; }
    constexpr auto modulus() const noexcept -> double { return m_real * m_real + m_imag * m_imag; }
    // Non-member function which accesses private data
    // This is needed to write things like
    // double d; complex_number c; 
    // complex_number e = d*c;
    // Because the operator is called with the LHS as the refering object
    friend constexpr auto operator*(double x, const complex_number&) noexcept -> complex_number;
    // Teach ostream how to output your class
    friend auto operator<<(std::ostream& os, const complex_number& c) -> std::ostream&;

private: 
    // Data variables. Private. Initialised.
    double m_real=0,m_imag=0;
};
// Note syntax for initialisation. You can assign to m_real and m_imag in the
// function body, but the initialiser syntax is more compact.
constexpr complex_number::complex_number(double re, double im) noexcept : m_real{re},m_imag{im} {}
// This is a constructor which gets its work done by calling another constructor.
// This is allowed since C++11.
constexpr complex_number::complex_number(double re) noexcept : complex_number{re,0} {}
// Note the compact notation for the return statement. The "type" of the
// return value is, of course, known from the function signature. So, 
// the compiler knows that it has to construct a complex_number from
// whatever that comes after the keyword "return". Since we have 
// only a set of braces with two arguments, it looks for a constructor
// with two double arguments, and uses that.
// The following functions are not member functions. They don't need to be.
constexpr auto operator+(const complex_number& b, const complex_number& c) noexcept -> complex_number
{
    return {b.real()+c.real(),b.imag()+c.imag()};
}
constexpr auto operator-(const complex_number& b, const complex_number& c) noexcept -> complex_number
{
    return {b.real()-c.real(),b.imag()-c.imag()};
}
constexpr auto operator*(const complex_number& b, const complex_number& c) noexcept -> complex_number
{
    return {b.real()*c.real()-b.imag()*c.imag(), b.real()*c.imag() + b.imag()*c.real()};
}
// Modifying operators do not construct a new object and return it, but
// instead directly change the data in the calling object. Look how
// the function returns the calling object through the "this" pointer!
// This is needed to write nested statements like z=z1*(z2+=z1);
constexpr auto complex_number::operator+=(const complex_number& c) noexcept -> complex_number&
{
    m_real+=c.m_real;
    m_imag+=c.m_imag;
    return *this;
}
constexpr auto complex_number::operator-=(const complex_number& c) noexcept -> complex_number&
{
    m_real-=c.m_real;
    m_imag-=c.m_imag;
    return *this;
}
constexpr auto complex_number::operator*=(const complex_number& c) noexcept -> complex_number&
{
    // Temporary store for new real value
    double tmprl=m_real*c.m_real-m_imag*c.m_imag;
    // Calculate new imaginary value using old real and imaginary parts
    m_imag=m_real*c.m_imag+m_imag*c.m_real;
    m_real=tmprl;
    return *this;
}
constexpr auto operator*(double x, const complex_number& c) noexcept -> complex_number
{
    return {x*c.m_real,x*c.m_imag};
}
auto operator<<(std::ostream& os, const complex_number& c) -> std::ostream&
{
    os << c.m_real;
    if (c.m_imag>0) os << '+';
    os << c.m_imag << 'i';
    return os;
}

auto main() -> int
{
    static_assert(complex_number { 0.1, -2.3 }.modulus() > 0, "");
    complex_number z0{0.3,0.84}, z;
    for (int i=0; i<10; ++i) {
        z = z*z + z0;
        std::cout << z << "\n";
    }
}
