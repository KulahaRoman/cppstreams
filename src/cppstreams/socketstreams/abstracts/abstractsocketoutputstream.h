#pragma once
#include <cpputils/exceptions/exceptions.h>
#include <cpputils/threadpool/threadpool.h>

#include "abstractsocketstream.h"


class AbstractSocketOutputStream : virtual protected AbstractSocketStream {
 protected:
  uint64_t write(const unsigned char* data, uint64_t size);
  void write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const Exception&)>& onFailure);

  uint64_t flush();
  void flush(const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const Exception&)>& onFailure);
};
