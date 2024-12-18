#include "Circle.hh"
#include "Triangle.hh"
#include <chrono>
#include <random>
#include <iostream>
#include <vector>
#include <memory>

using element_type = std::unique_ptr<Shape>;
constexpr auto N = 100000ul;
std::mt19937_64 engine;
std::discrete_distribution sel{ 0.5, 0.5 };
std::exponential_distribution length{ 1.0 };

auto name(const std::vector<element_type>& v, size_t i)
{
    return v[i]->name();
}

auto area(const std::vector<element_type>& v, size_t i)
{
    return v[i]->area();
}

void construct_objects(std::vector<element_type>& v)
{
    for (auto i = 0ul; i < N; ++i) {
        auto isel = sel(engine);
        switch (isel) {
        case 0: {
            auto radius = length(engine);
            auto centrepos = Point(length(engine), length(engine));
            v.emplace_back(std::make_unique<Circle>(radius, centrepos));
            break;
        }
        case 1: {
            auto v1 = Point(length(engine), length(engine));
            auto v2 = Point(length(engine), length(engine));
            auto v3 = Point(length(engine), length(engine));
            v.emplace_back(std::make_unique<Triangle>(v1, v2, v3));
            break;
        }
        };
    }
}

void calc_area_all(const std::vector<element_type>& v)
{
    auto max_loc = 0ul;
    auto max_area = 0.;
    for (size_t i = 0; i < v.size(); ++i) {
        auto ar = area(v, i);
        if (i < 5) {
            std::cout << i << ": " << name(v, i) << " with area "
                      << ar << "\n";
        }
        if (ar > max_area) {
            max_loc = i;
        }
    }

    std::cout << "Largest object: \n";
    auto nm = name(v, max_loc);
    auto ar = area(v, max_loc);
    std::cout << "Name : " << nm << ", area = " << ar << "\n";
}

int main()
{
    std::vector<element_type> shapes;
    shapes.reserve(N);

    auto t0 = std::chrono::steady_clock::now();
    construct_objects(shapes);
    auto t1 = std::chrono::steady_clock::now();
    calc_area_all(shapes);
    auto t2 = std::chrono::steady_clock::now();
    std::cout << "Object creation time for " << N << " objects, "
              << std::chrono::duration<double>(t1 - t0).count() << "\n"
              << "Area evaluation time for " << N << " objects, "
              << std::chrono::duration<double>(t2 - t1).count() << "\n";
}
