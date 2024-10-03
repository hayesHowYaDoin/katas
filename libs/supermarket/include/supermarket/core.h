#ifndef SUPERMARKET_CORE_H
#define SUPERMARKET_CORE_H

#include <cmath>
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

    friend Price
    operator+=(Price const& lhs, Price const& rhs)
    {
        return lhs + rhs;
    }

  private:
    float m_value;
};

struct Item {
    std::string name;
    Price unitPrice;
};

using ItemCount = uint32_t;

class Cart {
  public:
    explicit Cart(std::unordered_map<Item, ItemCount> const& items)
        : m_items{ items }
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

[[nodiscard]] Price calculateCartPrice(
    Cart const& cart,
    std::unordered_map<Item, std::vector<Discount> > const& discounts);

} // namespace supermarket

struct std::hash<supermarket::Item> {
    size_t
    operator()(supermarket::Item const& item) const noexcept
    {
        return std::hash<float>{}(item.unitPrice)
               ^ (std::hash<std::string>{}(item.name) << 1);
    }
};

#endif // SUPERMARKET_CORE_H