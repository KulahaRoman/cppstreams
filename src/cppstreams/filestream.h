#pragma once
#include "abstractfileinputstream.h"
#include "abstractfileoutputstream.h"
#include "stream.h"

namespace CppStreams {
class FileStream : private AbstractFileInputStream,
                   private AbstractFileOutputStream,
                   public Stream {
 public:
  FileStream(const std::string& file, bool binary);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  uint64_t Skip(uint64_t size) override;
  uint64_t Available() override;
  uint64_t Write(const unsigned char* data, uint64_t size) override;
  uint64_t Flush() override;
};
}  // namespace CppStreams
