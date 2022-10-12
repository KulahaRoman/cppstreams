#pragma once
#include <cpputils/exceptions/exception.h>

#include <functional>

class IAsyncInputStream {
 public:
  virtual void Read(unsigned char* data, uint64_t size,
                    const std::function<void(uint64_t)>& onSuccess,
                    const std::function<void(const Exception&)>& onFailure) = 0;
  virtual void Skip(uint64_t size,
                    const std::function<void(uint64_t)>& onSuccess,
                    const std::function<void(const Exception&)>& onFailure) = 0;
  virtual uint64_t Available() = 0;

  virtual ~IAsyncInputStream() {}
};
