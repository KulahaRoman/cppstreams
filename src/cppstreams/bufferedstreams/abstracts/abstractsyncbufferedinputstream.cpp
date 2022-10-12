#include "abstractsyncbufferedinputstream.h"

AbstractSyncBufferedInputStream::AbstractSyncBufferedInputStream(
    const std::shared_ptr<IInputStream>& stream, uint64_t bufferSize)
    : AbstractBufferedInputStream(bufferSize), stream(stream) {}

uint64_t AbstractSyncBufferedInputStream::read(unsigned char* data,
                                               uint64_t size) {
  auto readDataSize = 0ull;

  while (readDataSize < size) {
    if (!readBufferCached) {
      stream->Read(readBuffer.data(), readBuffer.size());
      processReadBuffer();
      readBufferCached = true;
    }

    readPortion(data, size, readDataSize);

    if (readBufferPos == readBuffer.size()) {
      resetReadBuffer();
    }
  }

  return readDataSize;
}

uint64_t AbstractSyncBufferedInputStream::skip(uint64_t size) {
  auto bufferSize = static_cast<uint64_t>(readBuffer.size());

  //            buffer
  //  ._______________________.
  //  |_______________________|
  //          |_______________|
  //      position    |
  //               remaining
  auto currentBufferRemaining = bufferSize - readBufferPos;

  if (size >= currentBufferRemaining) {
    readBufferCached = false;

    // Calculate how much bytes we should skip (nBytesToSkip) before reading
    // certain part of source stream.

    auto nBytesToRead = size - currentBufferRemaining;
    auto nBuffers = nBytesToRead / bufferSize + 1ull;
    auto nBytesToSkip = nBuffers * bufferSize;

    if (nBytesToSkip + bufferSize > stream->Available()) {
      throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
          L"Failed to skip bytes (insufficient bytes available)."
#else
          "Failed to skip bytes (insufficient bytes available)."
#endif
      );
    }

    stream->Skip(nBytesToSkip);
    stream->Read(readBuffer.data(), bufferSize);

    processReadBuffer();

    readBufferCached = true;
    readBufferPos = nBytesToRead % bufferSize;
  } else {
    readBufferPos += size;
  }

  return size;
}

uint64_t AbstractSyncBufferedInputStream::available() {
  return stream->Available();
}