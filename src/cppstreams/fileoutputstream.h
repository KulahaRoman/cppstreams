#pragma once
#include "abstractfileoutputstream.h"
#include "outputstream.h"

namespace CppStreams {
class FileOutputStream : private AbstractFileOutputStream, public OutputStream {
 public:
  FileOutputStream(const std::string& file, bool binary);

  uint64_t Write(const unsigned char* data, uint64_t size) override;
  uint64_t Flush() override;
};
}  // namespace CppStreams
