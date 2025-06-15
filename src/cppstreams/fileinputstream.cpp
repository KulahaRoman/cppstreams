#include "fileinputstream.h"

namespace CppStreams {
FileInputStream::FileInputStream(const std::string& file, bool binary)
    : AbstractFileStream(
          file,
          std::ios::in | (binary ? std::ios::binary : std::ios::openmode(0))) {}

uint64_t FileInputStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

uint64_t FileInputStream::Skip(uint64_t nBytes) { return skip(nBytes); }

uint64_t FileInputStream::Available() { return available(); }
}  // namespace CppStreams
