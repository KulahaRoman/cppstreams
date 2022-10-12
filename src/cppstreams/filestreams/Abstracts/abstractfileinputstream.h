#pragma once
#include <vector>

#include "abstractfilestream.h"

class AbstractFileInputStream : virtual public AbstractFileStream {
 protected:
  AbstractFileInputStream();

  uint64_t read(unsigned char* data, uint64_t size);
  uint64_t skip(uint64_t size);
  uint64_t available();

 protected:
  std::streampos gpos;
};
