#ifndef LCDIGITS_DIGIT_H
#define LCDIGITS_DIGIT_H

#include <array>
#include <cstdint>
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

    std::string_view firstRow;
    std::string_view secondRow;
    std::string_view thirdRow;
};

}

#endif // LCDIGITS_DIGIT_H
