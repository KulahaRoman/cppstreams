#pragma once
#include "abstractbufferedoutputstream.h"
#include "outputstream.h"

namespace CppStreams {
class BufferedOutputStream : protected AbstractBufferedOutputStream,
                             public OutputStream {
 public:
  BufferedOutputStream(const std::shared_ptr<OutputStream>& stream,
                       uint64_t bufferSize);

  uint64_t Write(const unsigned char* data, uint64_t size) override;
  uint64_t Flush() override;
};
}  // namespace CppStreams
