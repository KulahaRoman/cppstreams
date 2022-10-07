#include "abstractbufferedoutputstream.h"

AbstractBufferedOutputStream::AbstractBufferedOutputStream(uint64_t bufferSize)
    : writeBuffer(static_cast<size_t>(bufferSize)) {
  resetWriteBuffer();
}

void AbstractBufferedOutputStream::processWriteBuffer() {}

void AbstractBufferedOutputStream::writePortion(const unsigned char* data,
                                                uint64_t size,
                                                uint64_t& writtenDataSize) {
  auto dataPointers = calculateWriteDataPointers(
      writeBuffer.size(), writeBufferPos, size, writtenDataSize);

  std::copy(data + dataPointers.first, data + dataPointers.second,
            writeBuffer.data() + writeBufferPos);

  auto portionSize = dataPointers.second - dataPointers.first;

  writeBufferPos += portionSize;
  writtenDataSize += portionSize;
}

void AbstractBufferedOutputStream::resetWriteBuffer() {
  std::memset(writeBuffer.data(), 0, writeBuffer.size());
  writeBufferPos = 0ull;
}

std::pair<uint64_t, uint64_t>
AbstractBufferedOutputStream::calculateWriteDataPointers(uint64_t bufferSize,
                                                         uint64_t bufferPos,
                                                         uint64_t dataSize,
                                                         uint64_t doneSize) {
  auto remainingBufferSpace = bufferSize - bufferPos;
  auto remainingDataSize = dataSize - doneSize;

  auto portionSize = remainingDataSize < remainingBufferSpace
                         ? remainingDataSize
                         : remainingBufferSpace;

  auto beginPointer = bufferPos + doneSize;
  auto endPointer = beginPointer + portionSize;

  return std::make_pair(beginPointer, endPointer);
}
