#ifndef MINEFIELDS_IO_H
#define MINEFIELDS_IO_H

#include <fstream>


namespace minefields::io {

void getHints(std::istream& input, std::ostream& output);

} // namespace minefields::io


#endif // MINEFIELDS_IO_H