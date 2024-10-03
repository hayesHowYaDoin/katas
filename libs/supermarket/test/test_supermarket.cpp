#include <gtest/gtest.h>

#include "supermarket/supermarket.h"

TEST(SupermarketTest, TwentyPercentOff)
{
    using namespace supermarket;

    Item cheese{ "cheese", Price(0.25f) };

    std::unordered_map<Item, ItemCount> items = { { cheese, 10 } };
    Cart cart{ items };

    // Define a discount function
    Discount twentyPercentOff = [](Price const& totalPrice, size_t itemCount) {
        return percentOff(totalPrice, itemCount, 0.2f);
    };

    // Initialize the unordered_map with Item keys and Discounts values
    std::unordered_map<Item, std::vector<Discount> > discounts{
        { cheese, std::vector<Discount>{ twentyPercentOff } }
    };

    // Use the map in your test
    float total = calculateCartTotal(cart, discounts).raw();
    EXPECT_FLOAT_EQ(total, 0.5f);
}
