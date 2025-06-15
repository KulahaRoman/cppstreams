#include "bufferedoutputstream.h"

namespace CppStreams {
BufferedOutputStream::BufferedOutputStream(
    const std::shared_ptr<OutputStream>& stream, uint64_t bufferSize)
    : AbstractBufferedOutputStream(stream, bufferSize) {}

uint64_t BufferedOutputStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

uint64_t BufferedOutputStream::Flush() { return flush(); }
}  // namespace CppStreams
