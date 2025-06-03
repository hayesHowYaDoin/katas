#ifndef LCDIGITS_CORE_H
#define LCDIGITS_CORE_H

#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <stdexcept>
#include <string_view>

namespace lcdigits {

class DigitError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct Digit {
    [[nodiscard]] static constexpr Digit
    build(uint8_t value)
    {
        if(value > 9) {
            throw DigitError("Digit value must be between 0 and 9");
        }

        constexpr std::array<Digit, 10> digitLookup{
            Digit{ " _ ", "| |", "|_|" }, Digit{ "   ", "  |", "  |" },
            Digit{ " _ ", " _|", "|_ " }, Digit{ " _ ", " _|", " _|" },
            Digit{ "   ", "|_|", "  |" }, Digit{ " _ ", "|_ ", " _|" },
            Digit{ " _ ", "|_ ", "|_|" }, Digit{ " _ ", "  |", "  |" },
            Digit{ " _ ", "|_|", "|_|" }, Digit{ " _ ", "|_|", "  |" }

        };

        return digitLookup.at(value);
    }

    [[nodiscard]] constexpr friend bool
    operator==(Digit const& lhs, Digit const& rhs)
    {
        return lhs.rows == rhs.rows;
    }

    std::array<std::string_view, 3> rows;
};

namespace detail {

template <size_t N>
[[nodiscard]] constexpr std::array<Digit, N>
splitNumberToDigits(uint32_t value)
{
    std::array<Digit, N> digits;
    for(size_t digitIndex{ 0 }; digitIndex < N; ++digitIndex) {
        digits.at(digitIndex) = Digit::build(static_cast<uint8_t>(value % 10));
        value /= 10;
    }

    std::reverse(digits.begin(), digits.end());

    return digits;
}

}

template <size_t N>
class Number {
  public:
    constexpr
    Number(std::array<Digit, N> digits)
        : m_digits{ std::move(digits) }
    {
        // Intentionally left blank.
    }

    [[nodiscard]] static constexpr Number<N>
    fromNumber(uint32_t value)
    {
        return { detail::splitNumberToDigits<N>(value) };
    }

    [[nodiscard]] std::string
    getString() const
    {
        auto isZero
            = [](Digit const& digit) { return digit == Digit::build(0); };

        std::string result;
        for(size_t rowIndex{ 0 }; rowIndex < 3; ++rowIndex) {
            for(auto const& digit : m_digits | std::views::take_while(isZero)) {
                result += std::string(3, ' ');
            }

            for(auto const& digit : m_digits | std::views::drop_while(isZero)) {
                result += digit.rows.at(rowIndex);
            }

            result += '\n';
        }

        return result;
    }

  private:
    std::array<Digit, N> m_digits;
};

}

#endif // LCDIGITS_CORE_H
