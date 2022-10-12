#include "asyncbufferedoutputstream.h"

AsyncBufferedOutputStream::AsyncBufferedOutputStream(
    const std::shared_ptr<IAsyncOutputStream>& stream, uint64_t bufferSize)
    : AbstractAsyncBufferedOutputStream(stream, bufferSize) {}

void AsyncBufferedOutputStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  write(data, size, onSuccess, onFailure);
}

void AsyncBufferedOutputStream::Flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  flush(onSuccess, onFailure);
}
