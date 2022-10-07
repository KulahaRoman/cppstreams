#pragma once
#include <cpputils/threadpool/threadpool.h>

#include "abstractsocketstream.h"

class AbstractAsyncSocketOutputStream : virtual protected AbstractSocketStream {
 protected:
  void write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& callback);
  void flush(const std::function<void(uint64_t)>& callback);
};
