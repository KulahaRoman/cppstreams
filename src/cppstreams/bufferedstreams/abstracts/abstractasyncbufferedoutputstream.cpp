#include "abstractasyncbufferedoutputstream.h"

AbstractAsyncBufferedOutputStream::AbstractAsyncBufferedOutputStream(
    const std::shared_ptr<IAsyncOutputStream>& stream, uint64_t bufferSize)
    : AbstractBufferedOutputStream(bufferSize), stream(stream) {}

void AbstractAsyncBufferedOutputStream::write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  write(data, size, 0ull, onSuccess, onFailure);
}

void AbstractAsyncBufferedOutputStream::flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  if (writeBufferPos) {
    processWriteBuffer();
    stream->Write(
        writeBuffer.data(), writeBuffer.size(),
        [this, onSuccess](auto bytesWritten) {
          resetWriteBuffer();
          if (onSuccess) {
            onSuccess(bytesWritten);
          }
        },
        [this, onFailure](const auto& exc) {
          resetWriteBuffer();
          if (onFailure) {
            onFailure(exc);
          }
        });
    return;
  }

  ThreadPool::AcceptTask([onSuccess] {
    if (onSuccess) {
      onSuccess(0ull);
    }
  });
}

void AbstractAsyncBufferedOutputStream::write(
    const unsigned char* data, uint64_t size, uint64_t writtenDataSize,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  while (writtenDataSize < size) {
    writePortion(data, size, writtenDataSize);

    if (writeBufferPos == writeBuffer.size()) {
      processWriteBuffer();

      stream->Write(
          writeBuffer.data(), writeBuffer.size(),
          [this, data, size, writtenDataSize, onSuccess, onFailure](auto) {
            resetWriteBuffer();
            write(data, size, writtenDataSize, onSuccess, onFailure);
          },
          [this, onFailure](const auto& exc) {
            resetWriteBuffer();
            if (onFailure) {
              onFailure(exc);
            }
          });
      return;
    }
  }

  if (onSuccess) {
    onSuccess(writtenDataSize);
  }
}
