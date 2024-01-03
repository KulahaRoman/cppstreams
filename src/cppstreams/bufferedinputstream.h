#pragma once
#include "abstractbufferedinputstream.h"
#include "inputstream.h"

namespace CppStreams {
class BufferedInputStream
    : protected AbstractBufferedInputStream,
      public InputStream,
      public std::enable_shared_from_this<BufferedInputStream> {
 public:
  BufferedInputStream(const std::shared_ptr<InputStream>& stream,
                      uint64_t bufferSize);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  void Read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const std::exception&)>& onFailure =
                nullptr) override;

  uint64_t Skip(uint64_t size) override;
  void Skip(uint64_t size, const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const std::exception&)>& onFailure =
                nullptr) override;

  uint64_t Available() override;
};
}  // namespace CppStreams
