#ifndef SUPERMARKET_SUPERMARKET_H
#define SUPERMARKET_SUPERMARKET_H

#include <cmath>
#include <concepts>
#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace supermarket {

class Price {
  public:
    explicit Price(float value) : m_value{ value }
    {
        // Intentionally left blank.
    }

    [[nodiscard]] constexpr float
    raw() const
    {
        return m_value;
    }

    [[nodiscard]] constexpr float
    rounded() const
    {
        return std::round(m_value * 100.0f) / 100.0f;
    }

    friend Price
    operator+(Price const& lhs, Price const& rhs)
    {
        return Price{ lhs.raw() + rhs.raw() };
    }

    Price&
    operator+=(Price const& other)
    {
        m_value += other.raw();
        return *this;
    }

    friend Price
    operator/(Price const& lhs, float rhs)
    {
        return Price{ lhs.raw() / rhs };
    }

    friend Price
    operator*(Price const& lhs, float rhs)
    {
        return Price{ lhs.raw() * rhs };
    }

  private:
    float m_value;
};

struct Item {
    std::string name;
    Price unitPrice;

    friend bool
    operator==(Item const& lhs, Item const& rhs)
    {
        return lhs.name == rhs.name;
    }
};

} // namespace Item

namespace std {

template <>
struct hash<supermarket::Item> {
    size_t
    operator()(supermarket::Item const& item) const noexcept
    {
        return std::hash<float>{}(item.unitPrice.raw())
               ^ (std::hash<std::string>{}(item.name) << 1);
    }
};

} // namespace std

namespace supermarket {

using ItemCount = uint32_t;

class Cart {
  public:
    explicit Cart(std::unordered_map<Item, ItemCount> items)
        : m_items{ std::move(items) }
    {
        // Intentionally left blank.
    }

    [[nodiscard]] std::unordered_map<Item, ItemCount>
    getItemCounts() const
    {
        return m_items;
    }

  private:
    std::unordered_map<Item, ItemCount> m_items;
};

using Discount = std::function<Price(Price const&, size_t)>;

[[nodiscard]] Price calculateCartTotal(
    Cart const& cart,
    std::unordered_map<Item, std::vector<Discount> > const& discounts);

[[nodiscard]] Price buyOneGetSomeFree(Price const& totalPrice, size_t itemCount,
                                      uint32_t numberFree);

[[nodiscard]] Price percentOff(Price const& totalPrice, size_t itemCount,
                               float discount);

} // namespace supermarket

#endif // SUPERMARKET_SUPERMARKET_H