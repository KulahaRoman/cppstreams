#pragma once
#include <stdexcept>
#include <vector>

#include "abstractsocketstream.h"
#include "inputstream.h"

namespace CppStreams {
class AbstractSocketInputStream : public InputStream,
                                  virtual protected AbstractSocketStream {
 public:
  uint64_t Read(unsigned char* data, uint64_t size) override;
  void Read(
      unsigned char* data, uint64_t size,
      const std::function<void(uint64_t)>& onSuccess,
      const std::function<void(const std::exception&)>& onFailure) override;

  uint64_t Skip(uint64_t size) override;
  void Skip(
      uint64_t size, const std::function<void(uint64_t)>& onSuccess,
      const std::function<void(const std::exception&)>& onFailure) override;

  uint64_t Available() override;
};
}  // namespace CppStreams
