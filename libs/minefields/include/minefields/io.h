#ifndef MINEFIELDS_IO_H
#define MINEFIELDS_IO_H

#include <fstream>
#include <stdexcept>

namespace minefields::io {

class HintException : public std::runtime_error {
    using runtime_error::runtime_error;
};

void getHints(std::istream& input, std::ostream& output);

} // namespace minefields::io

#endif // MINEFIELDS_IO_H