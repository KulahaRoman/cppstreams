#pragma once
#include "../iinputstream.h"
#include "abstracts/abstractsyncbufferedinputstream.h"

class BufferedInputStream : protected AbstractSyncBufferedInputStream,
                            public IInputStream {
 public:
  BufferedInputStream(const std::shared_ptr<IInputStream>& stream,
                      uint64_t bufferSize);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  uint64_t Available() override;
  uint64_t Skip(uint64_t nBytes) override;
};
