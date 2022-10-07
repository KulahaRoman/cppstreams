#include "asyncbufferedinputstream.h"

AsyncBufferedInputStream::AsyncBufferedInputStream(
    const std::shared_ptr<IAsyncInputStream>& stream, uint64_t bufferSize)
    : AbstractAsyncBufferedInputStream(stream, bufferSize) {}

void AsyncBufferedInputStream::Read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& callback) {
  read(data, size, callback);
}

uint64_t AsyncBufferedInputStream::Available() { return available(); }

void AsyncBufferedInputStream::Skip(
    uint64_t nBytes, const std::function<void(uint64_t)>& callback) {
  skip(nBytes, callback);
}
