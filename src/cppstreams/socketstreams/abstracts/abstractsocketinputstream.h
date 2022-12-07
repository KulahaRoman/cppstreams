#pragma once
#include <cpputils/threadpool/threadpool.h>

#include <memory>
#include <stdexcept>
#include <vector>

#include "abstractsocketstream.h"

class AbstractSocketInputStream : virtual protected AbstractSocketStream {
 protected:
  uint64_t read(unsigned char* data, uint64_t size);
  void read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure);

  uint64_t skip(uint64_t nBytes);
  void skip(uint64_t size, const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure);

  uint64_t available();
};
