#include "supermarket/supermarket.h"

namespace supermarket {

[[nodiscard]] Price
calculateCartTotal(
    Cart const& cart,
    std::unordered_map<Item, std::vector<Discount> > const& discounts)
{
    Price total{ 0 };
    for(auto const& [item, count] : cart.getItemCounts()) {
        Price itemPrice{ item.unitPrice.raw() * static_cast<float>(count) };
        if(discounts.count(item)) {
            std::vector<Discount> itemDiscounts{ discounts.at(item) };
            for(auto const& discount : itemDiscounts) {
                itemPrice = discount(itemPrice, count);
            }
        }

        total += itemPrice;
    }

    return total;
}

Price
buyOneGetSomeFree(Price const& totalPrice, [[maybe_unused]] size_t itemCount,
                  uint32_t numberFree)
{
    return totalPrice / static_cast<float>(numberFree + 1);
}

Price
percentOff(Price const& totalPrice, [[maybe_unused]] size_t itemCount,
           float discountFraction)
{
    return totalPrice * discountFraction;
}

} // namespace supermarket
