#pragma once
#include <memory>
#include <stdexcept>
#include <vector>

#include "abstractsocketstream.h"

namespace CppStreams {
class AbstractSocketInputStream : virtual protected AbstractSocketStream {
 protected:
  uint64_t read(unsigned char* data, uint64_t size);
  uint64_t skip(uint64_t nBytes);
  uint64_t available();
};
}  // namespace CppStreams
