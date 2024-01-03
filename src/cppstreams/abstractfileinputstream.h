#pragma once
#include <cpputils/threadpool.h>

#include <functional>
#include <vector>

#include "abstractfilestream.h"
#include "inputstream.h"

namespace CppStreams {
class AbstractFileInputStream
    : public InputStream,
      virtual public AbstractFileStream,
      public std::enable_shared_from_this<AbstractFileInputStream> {
 public:
  uint64_t Read(unsigned char* data, uint64_t size) override;
  void Read(
      unsigned char* data, uint64_t size,
      const std::function<void(uint64_t)>& onSuccess,
      const std::function<void(const std::exception&)>& onFailure) override;

  uint64_t Skip(uint64_t size) override;
  void Skip(
      uint64_t size, const std::function<void(uint64_t)>& onSuccess,
      const std::function<void(const std::exception&)>& onFailure) override;

  uint64_t Available() override;

 protected:
  AbstractFileInputStream();

 protected:
  std::streampos gpos;
};
}  // namespace CppStreams
