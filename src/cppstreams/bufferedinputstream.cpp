#include "bufferedinputstream.h"

namespace CppStreams {
BufferedInputStream::BufferedInputStream(
    const std::shared_ptr<InputStream>& stream, uint64_t bufferSize)
    : AbstractBufferedInputStream(stream, bufferSize) {}

uint64_t BufferedInputStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

uint64_t BufferedInputStream::Skip(uint64_t nBytes) { return skip(nBytes); }

uint64_t BufferedInputStream::Available() { return available(); }
}  // namespace CppStreams
