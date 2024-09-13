#ifndef MINEFIELDS_HINT_H
#define MINEFIELDS_HINT_H

#include <cstddef>
#include <cstdint>
#include <functional>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <variant>
#include <vector>


struct Mine {};

struct Number {
    Number(uint8_t value): value{value} {}
    uint8_t value;
};

struct FieldPosition {
    size_t row;
    size_t column;

    bool operator==(FieldPosition const& other) const {
        return row == other.row && column == other.column;
    }
};

namespace std {
    template <>
    struct hash<FieldPosition> {
        size_t operator()(FieldPosition const& position) const noexcept {
            return std::hash<size_t>{}(position.row) ^ (std::hash<size_t>{}(position.column) << 1);
        }
    };
}

using HintfieldCell = std::variant<Mine, Number>;

class MinefieldException: public std::runtime_error {
  public:
    MinefieldException(std::string const& message): std::runtime_error {message} {}
};

class Hintfield {
  public:
    Hintfield(size_t rows, size_t columns, std::unordered_set<FieldPosition> const& minePositions);
    
    std::vector<std::vector<HintfieldCell>> field() const;
    size_t rows() const;
    size_t columns() const;

  private:
    static Number countNeighbors(
        size_t row,
        size_t column,
        std::unordered_set<FieldPosition> const& minePositions);

    std::vector<std::vector<HintfieldCell>> m_field;
};

#endif // MINEFIELDS_HINT_H