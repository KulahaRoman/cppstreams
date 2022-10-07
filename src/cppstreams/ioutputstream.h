#pragma once
#include <cstdint>

class IOutputStream {
 public:
  virtual uint64_t Write(const unsigned char*, uint64_t) = 0;
  virtual uint64_t Flush() = 0;

  virtual ~IOutputStream() {}
};
