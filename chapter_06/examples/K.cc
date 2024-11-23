#include <functional>
#include <iostream>
#include <random>
#include <vector>

inline auto power(double x, unsigned N) -> double
{
    double ans = 1;
    for (unsigned u = 0; u < N; ++u)
        ans *= x;
    return ans;
}
auto main() -> int
{
    std::vector d(1000000, 0.);
    double mu{ 1.0 };
    double sigma{ 35.8 };

    // Fill d with random numbers distributed as a normal
    // distribution with mu and sigma as given above.

    for (auto & el : d) el = gen();
    // ///////

    double mn = 0;
    for (auto r : d)
        mn += r;
    mn /= d.size();
    double kn = 0;
    for (auto r : d)
        kn += power(r - mn, 4);
    double kd = 0;
    for (auto r : d)
        kd += power(r - mn, 2);
    std::cout << d.size() * kn / (kd * kd) << "\n";
}

