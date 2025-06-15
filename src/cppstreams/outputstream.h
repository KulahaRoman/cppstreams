#pragma once
#include <cstdint>
#include <functional>

namespace CppStreams {
class OutputStream {
 public:
  virtual uint64_t Write(const unsigned char* data, uint64_t size) = 0;
  virtual uint64_t Flush() = 0;

  virtual ~OutputStream() = default;
};
}  // namespace CppStreams
