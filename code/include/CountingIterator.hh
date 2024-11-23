#pragma once
#include <compare>
#include <iterator>
#include <concepts>

namespace prf {
inline namespace utils {
    template <class T> requires std::is_integral<T>
    struct CountingIterator {
        using difference_type = std::make_signed_t<T>;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::random_access_iterator_tag;

        constexpr auto operator++(int) noexcept -> CountingIterator { return { val++ }; }
        constexpr auto operator++() noexcept -> CountingIterator&
        {
            ++val;
            return *this;
        }
        constexpr auto operator--(int) noexcept -> CountingIterator { return { val-- }; }
        constexpr auto operator--() noexcept -> CountingIterator&
        {
            --val;
            return *this;
        }
        constexpr auto operator+=(difference_type d) -> CountingIterator&
        {
            val += d;
            return *this;
        }
        constexpr auto operator-=(difference_type d) -> CountingIterator&
        {
            val -= d;
            return *this;
        }
        constexpr auto operator<=>(const CountingIterator& other) const noexcept = default;
        constexpr auto operator*() noexcept -> T& { return val; }
        constexpr auto operator*() const noexcept -> T { return val; }
        constexpr auto operator->() noexcept { return &val; }
        constexpr auto operator->() const noexcept { return &val; }
        constexpr auto operator-(CountingIterator other) const noexcept -> difference_type { return val - other.val; }
        constexpr auto operator+(difference_type d) const noexcept -> CountingIterator { return { val + d }; }
        constexpr auto operator[](size_t d) const noexcept { return val + d; }
        T val {};
    };
    template <Integer T>
    CountingIterator(T) -> CountingIterator<T>;

    template <Integer T>
    auto algo_counter(T&& i) -> CountingIterator<T> { return { i }; }
}
}
