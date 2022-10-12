#include "abstractasyncbufferedinputstream.h"

AbstractAsyncBufferedInputStream::AbstractAsyncBufferedInputStream(
    const std::shared_ptr<IAsyncInputStream>& stream, uint64_t bufferSize)
    : AbstractBufferedInputStream(bufferSize), stream(stream) {}

void AbstractAsyncBufferedInputStream::read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  read(data, size, 0ull, onSuccess, onFailure);
}

void AbstractAsyncBufferedInputStream::skip(
    uint64_t size, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  auto bufferSize = static_cast<uint64_t>(readBuffer.size());

  //            buffer
  //  ._______________________.
  //  |_______________________|
  //              |___________|
  //          position  |
  //                remaining
  auto currentBufferRemaining = bufferSize - readBufferPos;

  if (size >= currentBufferRemaining) {
    readBufferCached = false;

    // Calculate how much bytes we should skip (nBytesToSkip) before reading
    // certain part of source stream.

    auto nBytesToRead = size - currentBufferRemaining;
    auto nBuffers = nBytesToRead / bufferSize + 1ull;
    auto nBytesToSkip = nBuffers * bufferSize;

    if (nBytesToSkip + bufferSize > stream->Available()) {
      ThreadPool::AcceptTask([onFailure] {
        if (onFailure) {
          onFailure(RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
              L"Failed to skip bytes (insufficient bytes available)."
#else
              "Failed to skip bytes (insufficient bytes available)."
#endif
              ));
        }
      });
      return;
    }

    auto newReadBufferPos = nBytesToRead % bufferSize;

    stream->Skip(
        nBytesToSkip,
        [this, size, newReadBufferPos, onSuccess, onFailure](auto) {
          stream->Read(
              readBuffer.data(), readBuffer.size(),
              [this, size, newReadBufferPos, onSuccess](auto) {
                processReadBuffer();
                readBufferCached = true;
                readBufferPos = newReadBufferPos;

                if (onSuccess) {
                  onSuccess(size);
                }
              },
              [onFailure](const auto& exc) {
                if (onFailure) {
                  onFailure(exc);
                }
              });
        },
        [onFailure](const auto& exc) {
          if (onFailure) {
            onFailure(exc);
          }
        });
  } else {
    readBufferPos += size;

    ThreadPool::AcceptTask([onSuccess, size] {
      if (onSuccess) {
        onSuccess(size);
      }
    });
  }
}

uint64_t AbstractAsyncBufferedInputStream::available() {
  return stream->Available();
}

void AbstractAsyncBufferedInputStream::read(
    unsigned char* data, uint64_t size, uint64_t readDataSize,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  while (readDataSize < size) {
    if (!readBufferCached) {
      stream->Read(
          readBuffer.data(), readBuffer.size(),
          [this, data, size, readDataSize, onSuccess, onFailure](auto) {
            processReadBuffer();
            readBufferCached = true;
            read(data, size, readDataSize, onSuccess, onFailure);
          },
          [this, onFailure](const auto& exc) {
            resetReadBuffer();
            if (onFailure) {
              onFailure(exc);
            }
          });
      return;
    }

    readPortion(data, size, readDataSize);

    if (readBufferPos == readBuffer.size()) {
      resetReadBuffer();
    }
  }

  if (onSuccess) {
    onSuccess(readDataSize);
  }
}
