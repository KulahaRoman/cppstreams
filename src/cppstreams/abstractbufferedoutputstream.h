#pragma once
#include <cpputils/threadpool.h>

#include <cstdint>
#include <memory>
#include <utility>
#include <vector>

#include "outputstream.h"

namespace CppStreams {
class AbstractBufferedOutputStream {
 protected:
  AbstractBufferedOutputStream(const std::shared_ptr<OutputStream>& stream,
                               uint64_t bufferSize);

  uint64_t write(const unsigned char* data, uint64_t size);
  uint64_t flush();

 private:
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

 private:
  std::shared_ptr<OutputStream> stream;
};
}  // namespace CppStreams
