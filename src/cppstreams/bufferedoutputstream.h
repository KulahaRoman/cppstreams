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
  void Write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const std::exception&)>& onFailure =
                 nullptr) override;

  uint64_t Flush() override;
  void Flush(const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const std::exception&)>& onFailure =
                 nullptr) override;
};
}  // namespace CppStreams
