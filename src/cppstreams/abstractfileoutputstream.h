#pragma once
#include <cpputils/threadpool.h>

#include <functional>

#include "abstractfilestream.h"
#include "outputstream.h"

namespace CppStreams {
class AbstractFileOutputStream : public OutputStream,
                                 virtual public AbstractFileStream {
 public:
  uint64_t Write(const unsigned char* data, uint64_t size) override;
  void Write(
      const unsigned char* data, uint64_t size,
      const std::function<void(uint64_t)>& onSuccess,
      const std::function<void(const std::exception&)>& onFailure) override;

  uint64_t Flush() override;
  void Flush(
      const std::function<void(uint64_t)>& onSuccess,
      const std::function<void(const std::exception&)>& onFailure) override;

 protected:
  AbstractFileOutputStream();

 protected:
  std::streampos ppos;
};
}  // namespace CppStreams
