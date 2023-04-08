#include <iostream>
#include <limits>

void inBuffClear(std::istream &inStream) {
  inStream.clear();
  inStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void checkEOF(std::ios &stream) {
  if (stream.eof() == true) throw(std::exception());
}
