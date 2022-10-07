#include "abstractasyncbufferedoutputstream.h"

AbstractAsyncBufferedOutputStream::AbstractAsyncBufferedOutputStream(
    const std::shared_ptr<IAsyncOutputStream>& stream, uint64_t bufferSize)
    : AbstractBufferedOutputStream(bufferSize), stream(stream) {}

void AbstractAsyncBufferedOutputStream::write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& callback) {
  write(data, size, 0ull, callback);
}

void AbstractAsyncBufferedOutputStream::flush(
    const std::function<void(uint64_t)>& callback) {
  if (writeBufferPos) {
    processWriteBuffer();
    stream->Write(writeBuffer.data(), writeBuffer.size(),
                  [this, callback](auto bytesWritten) {
                    resetWriteBuffer();
                    callback(bytesWritten);
                  });
    return;
  }
  callback(0ull);
}

void AbstractAsyncBufferedOutputStream::write(
    const unsigned char* data, uint64_t size, uint64_t writtenDataSize,
    const std::function<void(uint64_t)>& finalCallback) {
  while (writtenDataSize < size) {
    writePortion(data, size, writtenDataSize);

    if (writeBufferPos == writeBuffer.size()) {
      processWriteBuffer();

      stream->Write(writeBuffer.data(), writeBuffer.size(),
                    [this, data, size, writtenDataSize, finalCallback](auto) {
                      resetWriteBuffer();
                      write(data, size, writtenDataSize, finalCallback);
                    });
      return;
    }
  }

  finalCallback(writtenDataSize);
}
