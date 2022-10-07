#include "abstractasyncbufferedinputstream.h"

AbstractAsyncBufferedInputStream::AbstractAsyncBufferedInputStream(
    const std::shared_ptr<IAsyncInputStream>& stream, uint64_t bufferSize)
    : AbstractBufferedInputStream(bufferSize), stream(stream) {}

void AbstractAsyncBufferedInputStream::read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& callback) {
  read(data, size, 0ull, callback);
}

uint64_t AbstractAsyncBufferedInputStream::available() {
  return stream->Available();
}

void AbstractAsyncBufferedInputStream::skip(
    uint64_t nBytes, const std::function<void(uint64_t)>& callback) {
  if (nBytes > stream->Available()) {
    throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
        L"Failed to skip bytes (insufficient bytes available)."
#else
        "Failed to skip bytes (insufficient bytes available)."
#endif
    );
  }

  auto bufferSize = static_cast<uint64_t>(readBuffer.size());

  //           buffer
  //  ._______________________.
  //  |_______________________|
  //              |
  //          position
  auto currentBufferPosition = readBufferPos % bufferSize;

  //            buffer
  //  ._______________________.
  //  |_______________________|
  //              |___________|
  //          position  |
  //                remaining
  auto currentBufferRemaining = bufferSize - currentBufferPosition;

  if (nBytes >= currentBufferRemaining) {
    readBufferCached = false;

    // Calculate how much bytes we should skip (nBytesToSkip) before reading
    // certain part of source stream.

    auto nBytesToRead = nBytes - currentBufferRemaining;
    auto nBuffers = nBytesToRead / bufferSize;
    auto nBytesToSkip = nBuffers * bufferSize;

    stream->Skip(nBytesToSkip, [this, nBytes, callback](auto) {
      stream->Read(readBuffer.data(), readBuffer.size(),
                   [this, nBytes, callback](auto) {
                     processReadBuffer();
                     readBufferCached = true;
                     readBufferPos += nBytes;

                     callback(nBytes);
                   });
    });
  } else {
    readBufferPos += nBytes;
  }
}

void AbstractAsyncBufferedInputStream::read(
    unsigned char* data, uint64_t size, uint64_t readDataSize,
    const std::function<void(uint64_t)>& finalCallback) {
  while (readDataSize < size) {
    if (!readBufferCached) {
      stream->Read(readBuffer.data(), readBuffer.size(),
                   [this, data, size, readDataSize, finalCallback](auto) {
                     processReadBuffer();
                     readBufferCached = true;
                     read(data, size, readDataSize, finalCallback);
                   });
      return;
    }

    readPortion(data, size, readDataSize);

    if (readBufferPos == readBuffer.size()) {
      resetReadBuffer();
    }
  }

  finalCallback(readDataSize);
}
