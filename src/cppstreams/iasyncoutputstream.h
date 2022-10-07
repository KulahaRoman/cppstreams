#pragma once
#include <functional>

class IAsyncOutputStream {
 public:
  virtual void Write(const unsigned char*, uint64_t,
                     const std::function<void(uint64_t)>&) = 0;
  virtual void Flush(const std::function<void(uint64_t)>&) = 0;

  virtual ~IAsyncOutputStream() {}
};
