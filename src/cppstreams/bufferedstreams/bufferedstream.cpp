#include "bufferedstream.h"

BufferedStream::BufferedStream(const std::shared_ptr<IStream>& stream,
                               uint64_t bufferSize)
    : AbstractSyncBufferedInputStream(stream, bufferSize),
      AbstractSyncBufferedOutputStream(stream, bufferSize) {}

uint64_t BufferedStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

uint64_t BufferedStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

uint64_t BufferedStream::Available() { return available(); }

uint64_t BufferedStream::Skip(uint64_t nBytes) { return skip(nBytes); }

uint64_t BufferedStream::Flush() { return flush(); }
