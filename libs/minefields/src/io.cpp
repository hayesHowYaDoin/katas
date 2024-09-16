#include <iostream>

#include "minefields/io.h"
#include "minefields/core.h"

namespace minefields::io {

void getHints(std::istream& input, std::ostream& output) {
    size_t rows, columns;
    input >> columns >> rows;

    std::unordered_set<core::CellPosition> mines;
    for(size_t row {0}; row < rows; ++row) {
        for(size_t column {0}; column < columns; ++column) {
            char cellValue;
            input >> cellValue;

            if(cellValue == '*') {
                mines.insert(core::CellPosition{.row {row}, .column {column}});
            }
        }
    }

    core::Hintfield hints(rows, columns, mines);

    for(auto const& row : hints.field()) {
        for(auto const& cell : row) {
            if(std::holds_alternative<core::Mine>(cell)) {
                output << '*';
            }
            else if(std::holds_alternative<core::Number>(cell)) {
                output << std::to_string(std::get<core::Number>(cell).value);
            }
            else {
                throw std::logic_error("Variant not implemented!");
            }
        }
        output << std::endl;
    }
}

} // namespace minefields::io
