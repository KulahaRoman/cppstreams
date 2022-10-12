#pragma once
#include <cpputils/logger/logger.h>
#include <cpputils/threadpool/threadpool.h>

#include <functional>

#include "abstractfileoutputstream.h"

class AbstractAsyncFileOutputStream : protected AbstractFileOutputStream {
 protected:
  void write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const Exception&)>& onFailure);
  void flush(const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const Exception&)>& onFailure);
};
