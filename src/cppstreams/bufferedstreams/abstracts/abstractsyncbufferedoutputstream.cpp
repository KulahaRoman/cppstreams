#include "abstractsyncbufferedoutputstream.h"

AbstractSyncBufferedOutputStream::AbstractSyncBufferedOutputStream(
    const std::shared_ptr<IOutputStream>& stream, uint64_t bufferSize)
    : AbstractBufferedOutputStream(bufferSize), stream(stream) {}

uint64_t AbstractSyncBufferedOutputStream::write(const unsigned char* data,
                                                 uint64_t size) {
  auto writtenDataSize = 0ull;

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

uint64_t AbstractSyncBufferedOutputStream::flush() {
  auto flushedBytes = 0ull;

  if (writeBufferPos) {
    processWriteBuffer();
    flushedBytes = stream->Write(writeBuffer.data(), writeBuffer.size());
    resetWriteBuffer();
    return writeBuffer.size();
  }

  return flushedBytes;
}
