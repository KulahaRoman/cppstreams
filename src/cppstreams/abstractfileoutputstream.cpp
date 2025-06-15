#include "abstractfileoutputstream.h"

namespace CppStreams {
AbstractFileOutputStream::AbstractFileOutputStream() : ppos(0) {}

uint64_t AbstractFileOutputStream::write(const unsigned char* data,
                                         uint64_t size) {
  if (!size) {
    return size;
  }

  file.seekp(ppos, std::ios::beg);

  try {
    file.write(reinterpret_cast<const char*>(data), size);
  } catch (...) {
    throw std::runtime_error("Failed to write bytes (IO error).");
  }

  ppos += size;

  return size;
}

uint64_t AbstractFileOutputStream::flush() {
  throw std::runtime_error(
      "Unsupported stream method (Flush() for non-bufered stream).");
  return 0ull;
}
}  // namespace CppStreams
