#pragma once
#include "abstractfileoutputstream.h"
#include "outputstream.h"

namespace CppStreams {
class FileOutputStream : private AbstractFileOutputStream,
                         public OutputStream,
                         public std::enable_shared_from_this<FileOutputStream> {
 public:
  FileOutputStream(const std::string& file, bool binary);

  uint64_t Write(const unsigned char* data, uint64_t size) override;
  void Write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const std::exception&)>& onFailure =
                 nullptr) override;

  uint64_t Flush() override;
  void Flush(const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const std::exception&)>& onFailure =
                 nullptr) override;
};
}  // namespace CppStreams
