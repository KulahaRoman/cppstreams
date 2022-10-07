#include "asyncbufferedstream.h"

AsyncBufferedStream::AsyncBufferedStream(
    const std::shared_ptr<IAsyncStream>& stream, uint64_t bufferSize)
    : AbstractAsyncBufferedInputStream(stream, bufferSize),
      AbstractAsyncBufferedOutputStream(stream, bufferSize) {}

void AsyncBufferedStream::Write(const unsigned char* data, uint64_t size,
                                const std::function<void(uint64_t)>& callback) {
  write(data, size, callback);
}

void AsyncBufferedStream::Read(unsigned char* data, uint64_t size,
                               const std::function<void(uint64_t)>& callback) {
  read(data, size, callback);
}

uint64_t AsyncBufferedStream::Available() { return available(); }

void AsyncBufferedStream::Skip(uint64_t nBytes,
                               const std::function<void(uint64_t)>& callback) {
  skip(nBytes, callback);
}

void AsyncBufferedStream::Flush(const std::function<void(uint64_t)>& callback) {
  flush(callback);
}
