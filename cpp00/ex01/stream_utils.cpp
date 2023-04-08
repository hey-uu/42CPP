#include "stream_utils.hpp"
#include <iostream>
#include <limits>

void utils::checkEOF(std::ios &stream)
{
    if (stream.eof() == true)
        throw(std::exception());
}
