#include "bufferedinputstream.h"

BufferedInputStream::BufferedInputStream(
    const std::shared_ptr<IInputStream>& stream, uint64_t bufferSize)
    : AbstractSyncBufferedInputStream(stream, bufferSize) {}

uint64_t BufferedInputStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

uint64_t BufferedInputStream::Skip(uint64_t size) { return skip(size); }

uint64_t BufferedInputStream::Available() { return available(); }