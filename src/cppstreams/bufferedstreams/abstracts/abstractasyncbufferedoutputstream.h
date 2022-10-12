#pragma once
#include <cpputils/threadpool/threadpool.h>

#include <memory>

#include "../../iasyncoutputstream.h"
#include "abstractbufferedoutputstream.h"


class AbstractAsyncBufferedOutputStream
    : protected AbstractBufferedOutputStream {
 public:
  AbstractAsyncBufferedOutputStream(
      const std::shared_ptr<IAsyncOutputStream>& stream, uint64_t bufferSize);

 protected:
  void write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const Exception&)>& onFailure);
  void flush(const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const Exception&)>& onFailure);

 private:
  void write(const unsigned char* data, uint64_t size, uint64_t writtenDataSize,
             const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const Exception&)>& onFailure);

 private:
  std::shared_ptr<IAsyncOutputStream> stream;
};
