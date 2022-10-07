#include "abstractbufferedinputstream.h"

AbstractBufferedInputStream::AbstractBufferedInputStream(uint64_t bufferSize)
    : readBuffer(static_cast<size_t>(bufferSize)) {
  resetReadBuffer();
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
