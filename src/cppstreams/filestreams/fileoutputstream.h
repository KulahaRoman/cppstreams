#pragma once
#include "../outputstream.h"
#include "abstracts/abstractfileoutputstream.h"

class FileOutputStream : private AbstractFileOutputStream, public OutputStream {
 public:
  FileOutputStream(const
#if defined(UNICODE) || defined(_UNICODE)
                   std::wstring
#else
                   std::string
#endif
                       & file,
                   bool binary);

  uint64_t Write(const unsigned char* data, uint64_t size) override;
  void Write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const Exception&)>& onFailure =
                 nullptr) override;

  uint64_t Flush() override;
  void Flush(const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const Exception&)>& onFailure =
                 nullptr) override;
};
