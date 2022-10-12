#pragma once
#include <cpputils/exceptions/exception.h>

#include <functional>

class IAsyncOutputStream {
 public:
  virtual void Write(
      const unsigned char* data, uint64_t size,
      const std::function<void(uint64_t)>& onSuccess,
      const std::function<void(const Exception&)>& onFailure) = 0;
  virtual void Flush(
      const std::function<void(uint64_t)>& onSuccess,
      const std::function<void(const Exception&)>& onFailure) = 0;

  virtual ~IAsyncOutputStream() {}
};
