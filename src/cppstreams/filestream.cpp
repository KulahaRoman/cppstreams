#include "filestream.h"

namespace CppStreams {
FileStream::FileStream(const std::string& file, bool binary)
    : AbstractFileStream(
          file, std::ios::in | std::ios::out |
                    (binary ? std::ios::binary : std::ios::openmode(0))) {}

uint64_t FileStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

uint64_t FileStream::Skip(uint64_t nBytes) { return skip(nBytes); }

uint64_t FileStream::Available() { return available(); }

uint64_t FileStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

uint64_t FileStream::Flush() { return flush(); }
}  // namespace CppStreams
