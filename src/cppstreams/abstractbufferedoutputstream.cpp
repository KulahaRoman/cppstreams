#include "abstractbufferedoutputstream.h"

namespace CppStreams {
AbstractBufferedOutputStream::AbstractBufferedOutputStream(
    const std::shared_ptr<OutputStream>& stream, uint64_t bufferSize)
    : stream(stream), writeBuffer(static_cast<size_t>(bufferSize)) {
  resetWriteBuffer();
}

uint64_t AbstractBufferedOutputStream::write(const unsigned char* data,
                                             uint64_t size) {
  uint64_t writtenDataSize = 0ull;

  while (writtenDataSize < size) {
    writePortion(data, size, writtenDataSize);

    if (writeBufferPos == writeBuffer.size()) {
      processWriteBuffer();
      stream->Write(writeBuffer.data(), writeBuffer.size());
      resetWriteBuffer();
    }
  }

  return writtenDataSize;
}

uint64_t AbstractBufferedOutputStream::flush() {
  auto flushedBytes = 0ull;

  if (writeBufferPos) {
    processWriteBuffer();
    flushedBytes = stream->Write(writeBuffer.data(), writeBuffer.size());
    resetWriteBuffer();
    return writeBuffer.size();
  }

  return flushedBytes;
}

void AbstractBufferedOutputStream::processWriteBuffer() {}

void AbstractBufferedOutputStream::writePortion(const unsigned char* data,
                                                uint64_t size,
                                                uint64_t& writtenDataSize) {
  auto dataPointers = calculateWriteDataPointers(
      writeBuffer.size(), writeBufferPos, size, writtenDataSize);

  auto portionSize = dataPointers.second - dataPointers.first;

  std::copy(data + writtenDataSize, data + writtenDataSize + portionSize,
            writeBuffer.data() + writeBufferPos);

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

  auto beginPointer = bufferPos;
  auto endPointer = beginPointer + portionSize;

  return std::make_pair(beginPointer, endPointer);
}
}  // namespace CppStreams
