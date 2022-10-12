#pragma once
#include "../iasyncinputstream.h"
#include "abstracts/abstractasyncbufferedinputstream.h"

class AsyncBufferedInputStream : protected AbstractAsyncBufferedInputStream,
                                 public IAsyncInputStream {
 public:
  AsyncBufferedInputStream(const std::shared_ptr<IAsyncInputStream>& stream,
                           uint64_t bufferSize);

  void Read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure) override;
  void Skip(uint64_t nBytes, const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure) override;
  uint64_t Available() override;
};
