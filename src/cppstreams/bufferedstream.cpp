#include "bufferedstream.h"

namespace CppStreams {
BufferedStream::BufferedStream(const std::shared_ptr<Stream>& stream,
                               uint64_t bufferSize)
    : AbstractBufferedInputStream(stream, bufferSize),
      AbstractBufferedOutputStream(stream, bufferSize) {}

uint64_t BufferedStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

uint64_t BufferedStream::Skip(uint64_t nBytes) { return skip(nBytes); }

uint64_t BufferedStream::Available() { return available(); }

uint64_t BufferedStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

uint64_t BufferedStream::Flush() { return flush(); }
}  // namespace CppStreams
