#pragma once
#include <cpputils/exceptions/exceptions.h>

#include <memory>

#include "../../iinputStream.h"
#include "abstractbufferedinputstream.h"

class AbstractSyncBufferedInputStream : protected AbstractBufferedInputStream {
 public:
  AbstractSyncBufferedInputStream(const std::shared_ptr<IInputStream>& stream,
                                  uint64_t bufferSize);

 protected:
  uint64_t read(unsigned char* data, uint64_t size);
  uint64_t skip(uint64_t size);
  uint64_t available();

 private:
  std::shared_ptr<IInputStream> stream;
};
