#pragma once
#include "../iasyncoutputstream.h"
#include "abstracts/abstractasyncbufferedoutputstream.h"

class AsyncBufferedOutputStream : protected AbstractAsyncBufferedOutputStream,
                                  public IAsyncOutputStream {
 public:
  AsyncBufferedOutputStream(const std::shared_ptr<IAsyncOutputStream>& stream,
                            uint64_t bufferSize);

  void Write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& callback) override;
  void Flush(const std::function<void(uint64_t)>& callback) override;
};
