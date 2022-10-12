#pragma once
#include <cpputils/threadpool/threadpool.h>

#include "abstractsocketstream.h"

class AbstractAsyncSocketInputStream : virtual protected AbstractSocketStream {
 protected:
  void read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure);
  void skip(uint64_t size, const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure);
  uint64_t available();
};
