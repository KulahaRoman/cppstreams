#pragma once
#include <cstdint>
#include <utility>
#include <vector>

class AbstractBufferedOutputStream {
 protected:
  AbstractBufferedOutputStream(uint64_t bufferSize);

  virtual void processWriteBuffer();
  void writePortion(const unsigned char* data, uint64_t size,
                    uint64_t& writtenDataSize);
  void resetWriteBuffer();
  std::pair<uint64_t, uint64_t> calculateWriteDataPointers(uint64_t bufferSize,
                                                           uint64_t bufferPos,
                                                           uint64_t dataSize,
                                                           uint64_t doneSize);

 protected:
  std::vector<unsigned char> writeBuffer;
  uint64_t writeBufferPos;
};
