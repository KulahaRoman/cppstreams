#pragma once
#include <cstdint>
#include <functional>

namespace CppStreams {
class OutputStream {
 public:
  virtual uint64_t Write(const unsigned char* data, uint64_t size) = 0;
  virtual void Write(const unsigned char* data, uint64_t size,
                     const std::function<void(uint64_t)>& onSuccess,
                     const std::function<void(const std::exception&)>&
                         onFailure = nullptr) = 0;

  virtual uint64_t Flush() = 0;
  virtual void Flush(const std::function<void(uint64_t)>& onSuccess,
                     const std::function<void(const std::exception&)>&
                         onFailure = nullptr) = 0;

  virtual ~OutputStream() {}
};
}  // namespace CppStreams
