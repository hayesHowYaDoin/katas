#include <iostream>
#include <sstream>

#include "minefields/io.h"

int
main(int argc, char* argv[])
{
    if(argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if(!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    std::stringstream output;
    minefields::io::getHints(inputFile, output);

    std::cout << output.str();

    return 0;
}