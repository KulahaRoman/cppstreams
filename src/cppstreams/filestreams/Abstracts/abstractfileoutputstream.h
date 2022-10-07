#pragma once
#include "abstractfilestream.h"

class AbstractFileOutputStream : virtual public AbstractFileStream {
 protected:
  AbstractFileOutputStream();

  uint64_t write(const unsigned char* data, uint64_t size);
  uint64_t flush();

 protected:
  std::streampos ppos;
};
