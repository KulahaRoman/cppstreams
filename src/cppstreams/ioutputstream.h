#pragma once
#include <cstdint>

class IOutputStream {
 public:
  virtual uint64_t Write(const unsigned char* data, uint64_t size) = 0;
  virtual uint64_t Flush() = 0;

  virtual ~IOutputStream() {}
};
