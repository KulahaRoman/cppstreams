#pragma once
#include <stdexcept>

#include "abstractsocketstream.h"
#include "outputstream.h"

namespace CppStreams {
class AbstractSocketOutputStream
    : public OutputStream,
      virtual protected AbstractSocketStream,
      public std::enable_shared_from_this<AbstractSocketOutputStream> {
 public:
  uint64_t Write(const unsigned char* data, uint64_t size) override;
  void Write(
      const unsigned char* data, uint64_t size,
      const std::function<void(uint64_t)>& onSuccess,
      const std::function<void(const std::exception&)>& onFailure) override;

  uint64_t Flush() override;
  void Flush(
      const std::function<void(uint64_t)>& onSuccess,
      const std::function<void(const std::exception&)>& onFailure) override;
};
}  // namespace CppStreams
