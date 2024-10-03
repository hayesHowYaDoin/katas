#include "supermarket/core.h"

namespace supermarket {

[[nodiscard]] Price
calculateCartPrice(
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

} // namespace supermarket
