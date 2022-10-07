#pragma once
#include "../iasyncstream.h"
#include "abstracts/abstractasyncfileinputstream.h"
#include "abstracts/abstractasyncfileoutputstream.h"

class AsyncFileStream : private AbstractAsyncFileInputStream,
                        private AbstractAsyncFileOutputStream,
                        public IAsyncStream {
 public:
  AsyncFileStream(const
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
  void Write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& callback) override;
  void Flush(const std::function<void(uint64_t)>& callback) override;
};
