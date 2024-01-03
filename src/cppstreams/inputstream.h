#pragma once
#include <cstdint>
#include <functional>

namespace CppStreams {
class InputStream {
 public:
  virtual uint64_t Read(unsigned char* data, uint64_t size) = 0;
  virtual void Read(unsigned char* data, uint64_t size,
                    const std::function<void(uint64_t)>& onSuccess,
                    const std::function<void(const std::exception&)>&
                        onFailure = nullptr) = 0;

  virtual uint64_t Skip(uint64_t size) = 0;
  virtual void Skip(uint64_t size,
                    const std::function<void(uint64_t)>& onSuccess,
                    const std::function<void(const std::exception&)>&
                        onFailure = nullptr) = 0;

  virtual uint64_t Available() = 0;

  virtual ~InputStream() = default;
};
}  // namespace CppStreams
