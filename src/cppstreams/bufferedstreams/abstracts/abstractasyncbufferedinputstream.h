#pragma once
#include <cpputils/exceptions/exceptions.h>

#include <memory>

#include "../../iasyncinputstream.h"
#include "abstractbufferedinputstream.h"

class AbstractAsyncBufferedInputStream : protected AbstractBufferedInputStream {
 public:
  AbstractAsyncBufferedInputStream(
      const std::shared_ptr<IAsyncInputStream>& stream, uint64_t bufferSize);

 protected:
  void read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& callback);
  uint64_t available();
  void skip(uint64_t nBytes, const std::function<void(uint64_t)>& callback);

 private:
  void read(unsigned char* data, uint64_t size, uint64_t readDataSize,
            const std::function<void(uint64_t)>& finalCallback);

 private:
  std::shared_ptr<IAsyncInputStream> stream;
};
