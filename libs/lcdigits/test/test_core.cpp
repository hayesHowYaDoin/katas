#include <gtest/gtest.h>

#include "lcdigits/core.h"

#include <gtest/gtest.h>
#include <tuple>
#include <vector>

#include "lcdigits/core.h"

class LCDigitsDigitTest : public ::testing::TestWithParam<
                              std::tuple<int, std::vector<std::string> > > {};

INSTANTIATE_TEST_SUITE_P(
    LCDigitsDigitTest, LCDigitsDigitTest,
    ::testing::Values(
        std::make_tuple(0, std::vector<std::string>{ " _ ", "| |", "|_|" }),
        std::make_tuple(1, std::vector<std::string>{ "   ", "  |", "  |" }),
        std::make_tuple(2, std::vector<std::string>{ " _ ", " _|", "|_ " }),
        std::make_tuple(3, std::vector<std::string>{ " _ ", " _|", " _|" }),
        std::make_tuple(4, std::vector<std::string>{ "   ", "|_|", "  |" }),
        std::make_tuple(5, std::vector<std::string>{ " _ ", "|_ ", " _|" }),
        std::make_tuple(6, std::vector<std::string>{ " _ ", "|_ ", "|_|" }),
        std::make_tuple(7, std::vector<std::string>{ " _ ", "  |", "  |" }),
        std::make_tuple(8, std::vector<std::string>{ " _ ", "|_|", "|_|" }),
        std::make_tuple(9, std::vector<std::string>{ " _ ", "|_|", "  |" })));

TEST_P(LCDigitsDigitTest, Digit)
{
    auto [digit, expected]{ GetParam() };
    auto lcdDigit = lcdigits::Digit::build(digit);

    for(size_t rowIndex{ 0 }; rowIndex < 3; ++rowIndex) {
        EXPECT_EQ(lcdDigit.rows.at(rowIndex), expected.at(rowIndex));
    }
}

TEST(LCDigitsTest, SplitNumberIntoDigitsFull)
{
    static constexpr auto digits{ lcdigits::detail::splitNumberToDigits<5>(
        12345) };
    static constexpr std::array<uint8_t, 5> expectedDigits{ 1, 2, 3, 4, 5 };
    for(size_t digitIndex{ 0 }; digitIndex < 5; ++digitIndex) {
        EXPECT_EQ(digits.at(digitIndex),
                  lcdigits::Digit::build(expectedDigits.at(digitIndex)));
    }
}

TEST(LCDigitsTest, SplitNumberIntoDigitsPartial)
{
    static constexpr auto digits{ lcdigits::detail::splitNumberToDigits<5>(
        789) };
    static constexpr std::array<uint8_t, 5> expectedDigits{ 0, 0, 7, 8, 9 };
    for(size_t digitIndex{ 0 }; digitIndex < 5; ++digitIndex) {
        EXPECT_EQ(digits.at(digitIndex),
                  lcdigits::Digit::build(expectedDigits.at(digitIndex)));
    }
}

class LCDigitsNumberTest
    : public ::testing::TestWithParam<std::tuple<int, std::string> > {};

INSTANTIATE_TEST_SUITE_P(
    LCDigitsNumberTest, LCDigitsNumberTest,
    ::testing::Values(std::make_tuple(5, "       _ \n      |_ \n       _|\n"),
                      std::make_tuple(12, "       _ \n     | _|\n     ||_ \n"),
                      std::make_tuple(333,
                                      " _  _  _ \n _| _| _|\n _| _| _|\n")));

TEST_P(LCDigitsNumberTest, Number)
{
    auto [number, expected]{ GetParam() };
    auto lcdNumber{ lcdigits::Number<3>::fromNumber(number) };
    EXPECT_EQ(lcdNumber.getString(), expected);
}
