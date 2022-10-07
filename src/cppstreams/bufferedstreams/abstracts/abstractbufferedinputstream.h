#pragma once
#include <cstdint>
#include <utility>
#include <vector>

class AbstractBufferedInputStream {
 protected:
  AbstractBufferedInputStream(uint64_t bufferSize);

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
};
