#pragma once
#include <cpputils/threadpool.h>

#include <functional>

#include "abstractfilestream.h"

namespace CppStreams {
class AbstractFileOutputStream : virtual public AbstractFileStream {
 protected:
  AbstractFileOutputStream();

  uint64_t write(const unsigned char* data, uint64_t size);
  uint64_t flush();

 protected:
  std::streampos ppos;
};
}  // namespace CppStreams
