#include "asyncbufferedoutputstream.h"

AsyncBufferedOutputStream::AsyncBufferedOutputStream(
    const std::shared_ptr<IAsyncOutputStream>& stream, uint64_t bufferSize)
    : AbstractAsyncBufferedOutputStream(stream, bufferSize) {}

void AsyncBufferedOutputStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& callback) {
  write(data, size, callback);
}

void AsyncBufferedOutputStream::Flush(
    const std::function<void(uint64_t)>& callback) {
  flush(callback);
}
