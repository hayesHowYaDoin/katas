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

namespace minefields::core {

class MinefieldException: public std::runtime_error {
public:
    MinefieldException(std::string const& message): std::runtime_error {message} {}
};


struct Mine {};

bool operator==(Mine const& first, Mine const& second);


struct Number {
    uint8_t value;
};

bool operator==(Number const& first, Number const& second);


using Cell = std::variant<Mine, Number>;


struct CellPosition {
    size_t row;
    size_t column;

    bool operator==(CellPosition const& other) const {
        return row == other.row && column == other.column;
    }
};


class Hintfield {
public:
    Hintfield(size_t rows, size_t columns, std::unordered_set<CellPosition> const& minePositions);
    
    std::vector<std::vector<Cell>> field() const;
    size_t rows() const;
    size_t columns() const;

private:
    static Number countNeighbors(
        size_t row,
        size_t column,
        std::unordered_set<CellPosition> const& minePositions);

    std::vector<std::vector<Cell>> m_field;
};

} // namespace minefields::core

template <>
struct std::hash<minefields::core::CellPosition> {
    size_t operator()(minefields::core::CellPosition const& position) const noexcept {
        return std::hash<size_t>{}(position.row) ^ (std::hash<size_t>{}(position.column) << 1);
    }
};


#endif // MINEFIELDS_HINT_H