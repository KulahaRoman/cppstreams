#include "abstractbufferedinputstream.h"

namespace CppStreams {
AbstractBufferedInputStream::AbstractBufferedInputStream(
    const std::shared_ptr<InputStream>& stream, uint64_t bufferSize)
    : stream(stream), readBuffer(static_cast<size_t>(bufferSize)) {
  resetReadBuffer();
}

uint64_t AbstractBufferedInputStream::read(unsigned char* data, uint64_t size) {
  uint64_t readDataSize = 0ull;

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

uint64_t AbstractBufferedInputStream::skip(uint64_t size) {
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
      throw std::runtime_error(
          "failed to skip bytes (insufficient bytes available)");
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

uint64_t AbstractBufferedInputStream::available() {
  return stream->Available();
}

void AbstractBufferedInputStream::processReadBuffer() {}

void AbstractBufferedInputStream::readPortion(unsigned char* data,
                                              uint64_t size,
                                              uint64_t& readDataSize) {
  auto dataPointers = calculateReadDataPointers(
      readBuffer.size(), readBufferPos, size, readDataSize);

  std::copy(readBuffer.data() + dataPointers.first,
            readBuffer.data() + dataPointers.second, data + readDataSize);

  auto portionSize = dataPointers.second - dataPointers.first;

  readBufferPos += portionSize;
  readDataSize += portionSize;
}

void AbstractBufferedInputStream::resetReadBuffer() {
  std::memset(readBuffer.data(), 0, readBuffer.size());
  readBufferPos = 0ull;
  readBufferCached = false;
}

std::pair<uint64_t, uint64_t>
AbstractBufferedInputStream::calculateReadDataPointers(uint64_t bufferSize,
                                                       uint64_t bufferPos,
                                                       uint64_t dataSize,
                                                       uint64_t doneSize) {
  auto remainingBufferSpace = bufferSize - bufferPos;
  auto remainingDataSize = dataSize - doneSize;

  auto portionSize = remainingDataSize < remainingBufferSpace
                         ? remainingDataSize
                         : remainingBufferSpace;

  auto beginPointer = bufferPos;
  auto endPointer = beginPointer + portionSize;

  return std::make_pair(beginPointer, endPointer);
}
}  // namespace CppStreams
