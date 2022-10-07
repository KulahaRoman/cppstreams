#pragma once
#include <cstdint>

class IInputStream {
 public:
  virtual uint64_t Read(unsigned char*, uint64_t) = 0;
  virtual uint64_t Available() = 0;
  virtual uint64_t Skip(uint64_t) = 0;

  virtual ~IInputStream() {}
};
