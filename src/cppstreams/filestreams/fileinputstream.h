#pragma once
#include "../inputstream.h"
#include "abstracts/abstractfileinputstream.h"

class FileInputStream : private AbstractFileInputStream, public InputStream {
 public:
  FileInputStream(const
#if defined(UNICODE) || defined(_UNICODE)
                  std::wstring
#else
                  std::string
#endif
                      & file,
                  bool binary);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  void Read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure =
                nullptr) override;

  uint64_t Skip(uint64_t size) override;
  void Skip(uint64_t size, const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure =
                nullptr) override;

  uint64_t Available() override;
};
