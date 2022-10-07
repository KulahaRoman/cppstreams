#pragma once
#include "abstractsocketstream.h"

class AbstractSocketOutputStream : virtual protected AbstractSocketStream {
 protected:
  uint64_t write(const unsigned char* data, uint64_t size);
  uint64_t flush();
};
