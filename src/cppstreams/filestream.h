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
  void Read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const std::exception&)>& onFailure =
                nullptr) override;

  uint64_t Skip(uint64_t size) override;
  void Skip(uint64_t size, const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const std::exception&)>& onFailure =
                nullptr) override;

  uint64_t Available() override;

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