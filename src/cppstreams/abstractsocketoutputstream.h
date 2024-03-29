#pragma once
#include <stdexcept>

#include "abstractsocketstream.h"

namespace CppStreams {
class AbstractSocketOutputStream : virtual protected AbstractSocketStream {
 protected:
  uint64_t write(const unsigned char* data, uint64_t size);
  void write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const std::exception&)>& onFailure);

  uint64_t flush();
  void flush(const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const std::exception&)>& onFailure);
};
}  // namespace CppStreams
