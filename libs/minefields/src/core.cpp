#include <array>

#include "minefields/core.h"

namespace minefields::core {

namespace _detail {

Number
countNeighbors(size_t row, size_t column,
               std::unordered_set<CellPosition> const& minePositions)
{
    auto castRow{ static_cast<int32_t>(row) };
    auto castColumn{ static_cast<int32_t>(column) };

    std::array<std::pair<int32_t, int32_t>, 8> coordinates{
        std::pair{ castRow, castColumn + 1 },
        std::pair{ castRow - 1, castColumn + 1 },
        std::pair{ castRow - 1, castColumn },
        std::pair{ castRow - 1, castColumn - 1 },
        std::pair{ castRow, castColumn - 1 },
        std::pair{ castRow + 1, castColumn - 1 },
        std::pair{ castRow + 1, castColumn },
        std::pair{ castRow + 1, castColumn + 1 },
    };

    uint8_t mineCount{ 0 };
    for(auto const& coordinate : coordinates) {
        if(coordinate.first < 0 || coordinate.second < 0) {
            continue;
        }

        auto position{ CellPosition{ static_cast<size_t>(coordinate.first),
                                     static_cast<size_t>(coordinate.second) } };

        if(minePositions.count(position)) {
            ++mineCount;
        }
    }

    return Number{ mineCount };
}

} // namespace _detail

Hintfield::Hintfield(size_t rows, size_t columns,
                     std::unordered_set<CellPosition> const& minePositions)
    : m_field{ rows, std::vector<Cell>(columns, Mine()) }
{
    for(size_t rowIndex{ 0 }; rowIndex < rows; ++rowIndex) {
        for(size_t columnIndex{ 0 }; columnIndex < columns; ++columnIndex) {
            if(minePositions.count(CellPosition{ rowIndex, columnIndex })
               == 0) {
                m_field.at(rowIndex).at(columnIndex) = _detail::countNeighbors(
                    rowIndex, columnIndex, minePositions);
            }
        }
    }
}

std::vector<std::vector<Cell> >
Hintfield::field() const
{
    return m_field;
}

size_t
Hintfield::rows() const
{
    return m_field.size();
}

size_t
Hintfield::columns() const
{
    return m_field.at(0).size();
}

bool
operator==(Mine const& first, Mine const& second)
{
    return true;
}

bool
operator==(Number const& first, Number const& second)
{
    return first.value == second.value;
}

} // namespace minefields::core
