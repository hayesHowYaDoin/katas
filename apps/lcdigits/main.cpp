#include <fstream>
#include <iostream>

#include "lcdigits/core.h"

int
main(int /* argc */, char** /* argv[] */)
{
    static constexpr auto digits{ lcdigits::Number<6>::fromNumber(12345) };
    std::cout << digits.getString() << std::endl;

    return 0;
}