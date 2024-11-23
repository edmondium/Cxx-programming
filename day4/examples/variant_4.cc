#include <array>
#include <cmath>
#include <iostream>
#include <type_traits>
#include <variant>

// For use as a "visitor", we create a variadic template class, with a
// variadic list of bases. The my_stapler class only imports the
// operator() from each of the bases.
template <class... Ts>
struct my_stapler : Ts... {
    using Ts::operator()...;
};

// The following statement is called a deduction rule : it means, "Hey, compiler!
// if you see an expression which looks like my_stapler{_, _, _ ...},
// interpret it as a constructor call for the class my_stapler<_, _, _ ...>".
template <class... Ts>
my_stapler(Ts...) -> my_stapler<Ts...>;

// With the above two statements, we have a mechanism to manufacture a
// new type from a comma separated list of typenames of types which have
// an overloaded operator(). E.g.,
// struct A { auto operator(int i) const { return i; } };
// struct B { auto operator(double d) const { return d; } };
// Then my_stapler{A, B} creates an object of type my_stapler<A, B>,
// which, because of the definition of my_stapler above, has two
// operator() in it, one taking an int argument inherited from A, the
// second taking a double, inherited from B.

auto main() -> int
{
    using namespace std;
    array<variant<int, double>, 6> powers { 8, 9.5, 11, 12.5, 14, 15.5 };
    cout << "Enter a small real number (< 2.0): ";
    double x;
    cin >> x;

    for (auto power : powers) {
        visit(
            // my_stapler needs a comma separated list of classes with operator()
            // overloaded. Lambda functions are locally created functionals which
            // fit the bill.
            my_stapler {
                [x](int val) { // first lambda handles situations when the content is int
                    cout << val << " is an integer.\n";
                    cout << "Calculating power by using the loop strategy: ";
                    double ans = 1.;
                    if (val > 0) {
                        for (int i = 0; i < val; ++i)
                            ans *= x;
                    } else {
                        double mul = 1.0 / x;
                        for (int i = 0; i > val; --i)
                            ans *= mul;
                    }
                    cout << x << "^" << val << " = " << ans << "\n";

                },
                [x](double val) { // the next lambda handles a variant when the content is double
                    cout << val << " is a double.\n";
                    cout << "Calculating power by using log and exp: ";
                    cout << x << "^" << val << " = " << exp(val * log(x)) << "\n";
                } // and so on, until we have exhausted all types in the variant.
            },
            power);
    }
}
