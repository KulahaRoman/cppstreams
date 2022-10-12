#include "asyncbufferedstream.h"

AsyncBufferedStream::AsyncBufferedStream(
    const std::shared_ptr<IAsyncStream>& stream, uint64_t bufferSize)
    : AbstractAsyncBufferedInputStream(stream, bufferSize),
      AbstractAsyncBufferedOutputStream(stream, bufferSize) {}

void AsyncBufferedStream::Read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  read(data, size, onSuccess, onFailure);
}

void AsyncBufferedStream::Skip(
    uint64_t nBytes, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  skip(nBytes, onSuccess, onFailure);
}

uint64_t AsyncBufferedStream::Available() { return available(); }

void AsyncBufferedStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  write(data, size, onSuccess, onFailure);
}

void AsyncBufferedStream::Flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  flush(onSuccess, onFailure);
}
