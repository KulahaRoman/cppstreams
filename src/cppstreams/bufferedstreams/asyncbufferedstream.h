#pragma once
#include "../iasyncstream.h"
#include "abstracts/abstractasyncbufferedinputstream.h"
#include "abstracts/abstractasyncbufferedoutputstream.h"

class AsyncBufferedStream : public IAsyncStream,
                            protected AbstractAsyncBufferedInputStream,
                            protected AbstractAsyncBufferedOutputStream {
 public:
  AsyncBufferedStream(const std::shared_ptr<IAsyncStream>& stream,
                      uint64_t bufferSize);

  void Read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& callback) override;
  uint64_t Available() override;
  void Skip(uint64_t nBytes,
            const std::function<void(uint64_t)>& callback) override;

  void Write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& callback) override;
  void Flush(const std::function<void(uint64_t)>& callback) override;
};
