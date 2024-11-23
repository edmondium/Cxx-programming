#include <iostream>
#include <vector>

class collect {
    std::vector<int> dat;
public:
    auto operator|(int i) -> collect&
    {
        dat.push_back(i);
        return *this;
    }
    auto operator~() const noexcept -> decltype(dat)
    {
        return dat;
    }
};
auto main() -> int
{
    auto C = collect{};
    C | 1 | 2 | 3 | 4 ;
    for (auto el : (~C)) {
        std::cout << el << "\n";
    }
}


