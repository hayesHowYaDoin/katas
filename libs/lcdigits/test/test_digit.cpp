#include <gtest/gtest.h>

#include "lcdigits/digit.h"

TEST(LCDigitsTest, Zero)
{
    auto zero{ lcdigits::Digit::build(0) };
    EXPECT_EQ(zero.firstRow, " _ ");
    EXPECT_EQ(zero.secondRow, "| |");
    EXPECT_EQ(zero.thirdRow, "|_|");
}

TEST(LCDigitsTest, One)
{
    auto zero{ lcdigits::Digit::build(1) };
    EXPECT_EQ(zero.firstRow, "   ");
    EXPECT_EQ(zero.secondRow, "  |");
    EXPECT_EQ(zero.thirdRow, "  |");
}

TEST(LCDigitsTest, Two)
{
    auto zero{ lcdigits::Digit::build(2) };
    EXPECT_EQ(zero.firstRow, " _ ");
    EXPECT_EQ(zero.secondRow, " _|");
    EXPECT_EQ(zero.thirdRow, "|_ ");
}

TEST(LCDigitsTest, Three)
{
    auto zero{ lcdigits::Digit::build(3) };
    EXPECT_EQ(zero.firstRow, " _ ");
    EXPECT_EQ(zero.secondRow, " _|");
    EXPECT_EQ(zero.thirdRow, " _|");
}

TEST(LCDigitsTest, Four)
{
    auto zero{ lcdigits::Digit::build(4) };
    EXPECT_EQ(zero.firstRow, "   ");
    EXPECT_EQ(zero.secondRow, "|_|");
    EXPECT_EQ(zero.thirdRow, "  |");
}

TEST(LCDigitsTest, Five)
{
    auto zero{ lcdigits::Digit::build(5) };
    EXPECT_EQ(zero.firstRow, " _ ");
    EXPECT_EQ(zero.secondRow, "|_ ");
    EXPECT_EQ(zero.thirdRow, " _|");
}

TEST(LCDigitsTest, Six)
{
    auto zero{ lcdigits::Digit::build(6) };
    EXPECT_EQ(zero.firstRow, " _ ");
    EXPECT_EQ(zero.secondRow, "|_ ");
    EXPECT_EQ(zero.thirdRow, "|_|");
}

TEST(LCDigitsTest, Seven)
{
    auto zero{ lcdigits::Digit::build(7) };
    EXPECT_EQ(zero.firstRow, " _ ");
    EXPECT_EQ(zero.secondRow, "  |");
    EXPECT_EQ(zero.thirdRow, "  |");
}

TEST(LCDigitsTest, Eight)
{
    auto zero{ lcdigits::Digit::build(8) };
    EXPECT_EQ(zero.firstRow, " _ ");
    EXPECT_EQ(zero.secondRow, "|_|");
    EXPECT_EQ(zero.thirdRow, "|_|");
}

TEST(LCDigitsTest, Nine)
{
    auto zero{ lcdigits::Digit::build(9) };
    EXPECT_EQ(zero.firstRow, " _ ");
    EXPECT_EQ(zero.secondRow, "|_|");
    EXPECT_EQ(zero.thirdRow, "  |");
}