#pragma once
#include "abstractbufferedinputstream.h"
#include "abstractbufferedoutputstream.h"
#include "stream.h"

namespace CppStreams {
class BufferedStream : protected AbstractBufferedInputStream,
                       protected AbstractBufferedOutputStream,
                       public Stream {
 public:
  BufferedStream(const std::shared_ptr<Stream>& stream, uint64_t bufferSize);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  uint64_t Skip(uint64_t size) override;
  uint64_t Available() override;
  uint64_t Write(const unsigned char* data, uint64_t size) override;
  uint64_t Flush() override;
};
}  // namespace CppStreams
