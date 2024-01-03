#pragma once
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace CppStreams {
class AbstractFileStream {
 protected:
  AbstractFileStream();
  AbstractFileStream(const std::string& file,
                     const std::ios::openmode& openMode);
  ~AbstractFileStream();

 protected:
  std::fstream file;
};
}  // namespace CppStreams
