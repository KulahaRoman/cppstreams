#include "bufferedoutputstream.h"

BufferedOutputStream::BufferedOutputStream(
    const std::shared_ptr<IOutputStream>& stream, uint64_t bufferSize)
    : AbstractSyncBufferedOutputStream(stream, bufferSize) {}

uint64_t BufferedOutputStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

uint64_t BufferedOutputStream::Flush() { return flush(); }
