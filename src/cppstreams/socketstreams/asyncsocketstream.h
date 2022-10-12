#pragma once
#include "../iasyncstream.h"
#include "abstracts/abstractasyncsocketinputstream.h"
#include "abstracts/abstractasyncsocketoutputstream.h"

class AsyncSocketStream : private AbstractAsyncSocketInputStream,
                          private AbstractAsyncSocketOutputStream,
                          public IAsyncStream {
 public:
  AsyncSocketStream(boost::asio::ip::tcp::socket&& socket);

  void Read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure) override;
  void Skip(uint64_t size, const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const Exception&)>& onFailure) override;
  uint64_t Available() override;
  void Write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const Exception&)>& onFailure) override;
  void Flush(const std::function<void(uint64_t)>& onSuccess,
             const std::function<void(const Exception&)>& onFailure) override;
};
