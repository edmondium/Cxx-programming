#include <iostream>
#include <memory>
#include <vector>
#include <type_traits>
using namespace std::string_literals;

void func1(int x) { std::cout << "Integer = " << x << "\n"; }
void func1(double x) { std::cout << "Double = " << x << "\n"; }
void func1(std::string x) { std::cout << "std::string = \"" << x << "\"\n"; }

class PolyVal {
    struct Internal {
        virtual ~Internal() noexcept = default;
        virtual auto clone() const -> std::unique_ptr<Internal> = 0;
        virtual void func1_() const = 0;
    };
    template <class T>
    struct Wrapped : public Internal {
        Wrapped(T ex) : obj{ex} {}
        ~Wrapped() noexcept override {}
        auto clone() const -> std::unique_ptr<Internal> override
        {
            return std::make_unique<Wrapped>(obj);
        }
        void func1_() const override
        {
            func1(obj);
        }
        T obj;
    };

public:
    template <class T>
    PolyVal(const T& var) : ptr{ std::make_unique<Wrapped<T>>(var) } {}
    PolyVal(const PolyVal& other) : ptr { other.ptr->clone() } {}

private:
    friend void func1(const PolyVal& pv) { pv.ptr->func1_(); }
    std::unique_ptr<Internal> ptr;
};

auto f(int i) -> PolyVal
{
    if (i % 2 == 0)
        return { 9 };
    else
        return { "Nine"s };
}

auto main() -> int
{
    std::vector<PolyVal> v;
    v.push_back(1);
    v.push_back(2.0);
    v.push_back("Green"s);

    for (auto&& elem : v) {
        func1(elem);
    }
    std::cout << "------------\n";
    for (int i = 0; i < 6; ++i) {
        std::cout << "Calling function with i = " 
            << i << " and receiving PolyVal by value\n";
        PolyVal X = f(i);
        func1(X);
    }
}

