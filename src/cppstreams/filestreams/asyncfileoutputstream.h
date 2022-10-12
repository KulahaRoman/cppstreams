#pragma once
#include "../iasyncoutputstream.h"
#include "abstracts/abstractasyncfileoutputstream.h"

class AsyncFileOutputStream : private AbstractAsyncFileOutputStream,
                              public IAsyncOutputStream {
 public:
  AsyncFileOutputStream(const
#if defined(UNICODE) || defined(_UNICODE)
                        std::wstring
#else
                        std::string
#endif
                            & file,
                        bool binary);

  void Write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const Exception&)>& onFailure) override;
  void Flush(const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const Exception&)>& onFailure) override;
};
