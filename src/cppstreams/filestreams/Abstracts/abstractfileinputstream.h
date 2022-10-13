#pragma once
#include <cpputils/threadpool/threadpool.h>

#include <functional>
#include <vector>

#include "abstractfilestream.h"


class AbstractFileInputStream : virtual public AbstractFileStream {
 protected:
  AbstractFileInputStream();

  uint64_t read(unsigned char* data, uint64_t size);
  void read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure);

  uint64_t skip(uint64_t size);
  void skip(uint64_t size, const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure);

  uint64_t available();

 protected:
  std::streampos gpos;
};
