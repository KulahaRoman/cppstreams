#pragma once
#include <memory>

#include "../../ioutputstream.h"
#include "abstractbufferedoutputstream.h"

class AbstractSyncBufferedOutputStream
    : protected AbstractBufferedOutputStream {
 public:
  AbstractSyncBufferedOutputStream(const std::shared_ptr<IOutputStream>& stream,
                                   uint64_t bufferSize);

 protected:
  uint64_t write(const unsigned char* data, uint64_t size);
  uint64_t flush();

 private:
  std::shared_ptr<IOutputStream> stream;
};
