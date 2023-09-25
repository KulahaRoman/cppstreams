#include "abstractfilestream.h"

namespace CppStreams {
AbstractFileStream::AbstractFileStream() {}

AbstractFileStream::AbstractFileStream(const std::string& file,
                                       const std::ios::openmode& openMode) {
  this->file.exceptions(std::ios::failbit | std::ios::badbit |
                        std::ios::eofbit);
  try {
    this->file.open(file, openMode);
  } catch (...) {
    throw std::runtime_error("Failed to open file stream: cannot open file.");
  }
}

AbstractFileStream::~AbstractFileStream() {
  if (file.is_open()) {
    file.close();
  }
}
}  // namespace CppStreams
