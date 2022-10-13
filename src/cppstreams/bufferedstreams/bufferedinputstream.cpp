#include "bufferedinputstream.h"

BufferedInputStream::BufferedInputStream(
    const std::shared_ptr<InputStream>& stream, uint64_t bufferSize)
    : AbstractBufferedInputStream(stream, bufferSize) {}

uint64_t BufferedInputStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

void BufferedInputStream::Read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  read(data, size, onSuccess, onFailure);
}

uint64_t BufferedInputStream::Skip(uint64_t nBytes) { return skip(nBytes); }

void BufferedInputStream::Skip(
    uint64_t size, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  skip(size, onSuccess, onFailure);
}

uint64_t BufferedInputStream::Available() { return available(); }