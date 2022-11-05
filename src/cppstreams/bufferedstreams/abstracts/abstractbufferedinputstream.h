#pragma once
#include <cpputils/exceptions/exceptions.h>
#include <cpputils/threadpool/threadpool.h>

#include <cstdint>
#include <memory>
#include <utility>
#include <vector>

#include "../../inputstream.h"

class AbstractBufferedInputStream {
 protected:
  AbstractBufferedInputStream(InputStream& stream, uint64_t bufferSize);

 protected:
  uint64_t read(unsigned char* data, uint64_t size);
  void read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure);

  uint64_t skip(uint64_t size);
  void skip(uint64_t size, const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure);

  uint64_t available();

 private:
  void read(unsigned char* data, uint64_t size, uint64_t readDataSize,
            const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure);

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
  InputStream& stream;
};
