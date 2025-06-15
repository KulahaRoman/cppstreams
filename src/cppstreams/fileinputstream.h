#pragma once
#include "abstractfileinputstream.h"
#include "inputstream.h"

namespace CppStreams {
class FileInputStream : private AbstractFileInputStream, public InputStream {
 public:
  FileInputStream(const std::string& file, bool binary);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  uint64_t Skip(uint64_t size) override;
  uint64_t Available() override;
};
}  // namespace CppStreams
