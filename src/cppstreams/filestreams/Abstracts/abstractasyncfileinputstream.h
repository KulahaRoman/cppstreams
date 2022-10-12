#pragma once
#include <cpputils/threadpool/threadpool.h>

#include <functional>

#include "abstractfileinputstream.h"

class AbstractAsyncFileInputStream : protected AbstractFileInputStream {
 protected:
  void read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure);
  void skip(uint64_t size, const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure);
};
