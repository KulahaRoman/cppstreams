#pragma once
#include <cstdint>
#include <memory>
#include <stdexcept>
#include <utility>
#include <vector>

#include "inputstream.h"

namespace CppStreams {
class AbstractBufferedInputStream {
 protected:
  AbstractBufferedInputStream(const std::shared_ptr<InputStream>& stream,
                              uint64_t bufferSize);

 protected:
  uint64_t read(unsigned char* data, uint64_t size);
  uint64_t skip(uint64_t size);
  uint64_t available();

 private:
  virtual void processReadBuffer();
  void readPortion(unsigned char* data, uint64_t size, uint64_t& readDataSize);
  void resetReadBuffer();
  std::pair<uint64_t, uint64_t> calculateReadDataPointers(uint64_t bufferSize,
                                                          uint64_t bufferPos,
                                                          uint64_t dataSize,
                                                          uint64_t doneSize);

 protected:
  std::vector<unsigned char> readBuffer;
  uint64_t readBufferPos;
  bool readBufferCached;

 private:
  std::shared_ptr<InputStream> stream;
};
}  // namespace CppStreams
