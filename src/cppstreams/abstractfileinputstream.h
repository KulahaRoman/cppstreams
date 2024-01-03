#pragma once
#include <cpputils/threadpool.h>

#include <functional>
#include <vector>

#include "abstractfilestream.h"

namespace CppStreams {
class AbstractFileInputStream : virtual public AbstractFileStream {
 protected:
  AbstractFileInputStream();

  uint64_t read(unsigned char* data, uint64_t size);
  void read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const std::exception&)>& onFailure);

  uint64_t skip(uint64_t size);
  void skip(uint64_t size, const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const std::exception&)>& onFailure);

  uint64_t available();

 protected:
  std::streampos gpos;
};
}  // namespace CppStreams
