#include "fileoutputstream.h"

namespace CppStreams {
FileOutputStream::FileOutputStream(const std::string& file, bool binary)
    : AbstractFileStream(
          file, std::ios::out |
                    (binary ? std::ios::binary : std::ios::openmode(0))) {}

uint64_t FileOutputStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

uint64_t FileOutputStream::Flush() { return flush(); }
}  // namespace CppStreams
