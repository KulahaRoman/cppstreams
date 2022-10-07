#pragma once
#include <memory>
#include <vector>

#include "abstractsocketstream.h"

class AbstractSocketInputStream : virtual protected AbstractSocketStream {
 protected:
  uint64_t read(unsigned char* data, uint64_t size);
  uint64_t available();
  uint64_t skip(uint64_t nBytes);
};
