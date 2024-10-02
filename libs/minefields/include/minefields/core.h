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

class MinefieldException : public std::runtime_error {
  public:
    using runtime_error::runtime_error;
};

struct Mine {
    friend bool
    operator==([[maybe_unused]] Mine const& first,
               [[maybe_unused]] Mine const& second)
    {
        return true;
    }
};

struct Number {
    uint8_t value;

    friend bool
    operator==(Number const& first, Number const& second)
    {
        return first.value == second.value;
    }
};

using Cell = std::variant<Mine, Number>;

struct CellPosition {
    size_t row;
    size_t column;

    friend bool
    operator==(CellPosition const& lhs, CellPosition const& rhs)
    {
        return lhs.row == rhs.row && lhs.column == rhs.column;
    }
};

class Hintfield {
  public:
    Hintfield(size_t rows, size_t columns,
              std::unordered_set<CellPosition> const& minePositions);

    std::vector<std::vector<Cell> > field() const;
    size_t rows() const;
    size_t columns() const;

  private:
    std::vector<std::vector<Cell> > m_field;
};

} // namespace minefields::core

template <>
struct std::hash<minefields::core::CellPosition> {
    size_t
    operator()(minefields::core::CellPosition const& position) const noexcept
    {
        return std::hash<size_t>{}(position.row)
               ^ (std::hash<size_t>{}(position.column) << 1);
    }
};

#endif // MINEFIELDS_HINT_H