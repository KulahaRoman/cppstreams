#pragma once
#include <stdexcept>

#include "abstractsocketstream.h"

namespace CppStreams {
class AbstractSocketOutputStream : virtual protected AbstractSocketStream {
 protected:
  uint64_t write(const unsigned char* data, uint64_t size);
  uint64_t flush();
};
}  // namespace CppStreams
