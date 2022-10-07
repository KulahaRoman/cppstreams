#pragma once
#include <functional>

class IAsyncInputStream {
 public:
  virtual void Read(unsigned char*, uint64_t,
                    const std::function<void(uint64_t)>&) = 0;
  virtual uint64_t Available() = 0;
  virtual void Skip(uint64_t, const std::function<void(uint64_t)>&) = 0;

  virtual ~IAsyncInputStream() {}
};
