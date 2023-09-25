#pragma once
#include <cpputils/threadpool/threadpool.h>

#include <functional>

#include "abstractfilestream.h"

namespace CppStreams {
class AbstractFileOutputStream : virtual public AbstractFileStream {
 protected:
  AbstractFileOutputStream();

  uint64_t write(const unsigned char* data, uint64_t size);
  void write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const std::exception&)>& onFailure);

  uint64_t flush();
  void flush(const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const std::exception&)>& onFailure);

 protected:
  std::streampos ppos;
};
}  // namespace CppStreams
