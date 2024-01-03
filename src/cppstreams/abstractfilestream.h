#pragma once
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace CppStreams {
class AbstractFileStream
    : public std::enable_shared_from_this<AbstractFileStream> {
 protected:
  AbstractFileStream();
  AbstractFileStream(const std::string& file,
                     const std::ios::openmode& openMode);
  ~AbstractFileStream();

 protected:
  std::fstream file;
};
}  // namespace CppStreams
