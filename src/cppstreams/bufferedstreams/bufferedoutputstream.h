#pragma once
#include "../ioutputstream.h"
#include "abstracts/abstractsyncbufferedoutputstream.h"

class BufferedOutputStream : protected AbstractSyncBufferedOutputStream,
                             public IOutputStream {
 public:
  BufferedOutputStream(const std::shared_ptr<IOutputStream>& stream,
                       uint64_t bufferSize);

  uint64_t Write(const unsigned char* data, uint64_t size) override;
  uint64_t Flush() override;
};
