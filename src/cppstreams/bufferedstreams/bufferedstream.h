#pragma once
#include "../istream.h"
#include "abstracts/abstractsyncbufferedinputstream.h"
#include "abstracts/abstractsyncbufferedoutputstream.h"

class BufferedStream : protected AbstractSyncBufferedInputStream,
                       protected AbstractSyncBufferedOutputStream,
                       public IStream {
 public:
  BufferedStream(const std::shared_ptr<IStream>& stream, uint64_t bufferSize);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  uint64_t Available() override;
  uint64_t Skip(uint64_t nBytes) override;

  uint64_t Write(const unsigned char* data, uint64_t size) override;
  uint64_t Flush() override;
};
