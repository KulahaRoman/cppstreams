#pragma once
#include "../iasyncinputstream.h"
#include "abstracts/abstractasyncfileinputstream.h"

class AsyncFileInputStream : private AbstractAsyncFileInputStream,
                             public IAsyncInputStream {
 public:
  AsyncFileInputStream(const
#if defined(UNICODE) || defined(_UNICODE)
                       std::wstring
#else
                       std::string
#endif
                           & file,
                       bool binary);

  void Read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& callback) override;
  uint64_t Available() override;
  void Skip(uint64_t nBytes,
            const std::function<void(uint64_t)>& callback) override;
};
