#include <gtest/gtest.h>

#include "minefields/core.h"


TEST(HintTest, NoMines) {
    using namespace minefields::core;

    Hintfield hints(2, 2, {});

    EXPECT_EQ(hints.rows(), 2);
    EXPECT_EQ(hints.columns(), 2);
    for(auto const& row : hints.field()) {
        for(auto const& cell : row) {
            EXPECT_TRUE(std::holds_alternative<Number>(cell));
        }
    }
}

TEST(HintTest, Mines) {
    using namespace minefields::core;

    std::unordered_set<CellPosition> mines {
        {1, 1},
        {2, 1},
        {4, 2},
    };
    Hintfield hints(5, 3, mines);

    std::vector<std::vector<Cell>> expectedField {
        {Number{1}, Number{1}, Number{1}},
        {Number{2}, Mine{},    Number{2}},
        {Number{2}, Mine{},    Number{2}},
        {Number{1}, Number{2}, Number{2}},
        {Number{0}, Number{1}, Mine{}},
    };
    

    EXPECT_EQ(hints.field(), expectedField);
}
