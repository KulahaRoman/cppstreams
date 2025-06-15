#pragma once
#include "abstractbufferedinputstream.h"
#include "inputstream.h"

namespace CppStreams {
class BufferedInputStream : protected AbstractBufferedInputStream,
                            public InputStream {
 public:
  BufferedInputStream(const std::shared_ptr<InputStream>& stream,
                      uint64_t bufferSize);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  uint64_t Skip(uint64_t size) override;
  uint64_t Available() override;
};
}  // namespace CppStreams
