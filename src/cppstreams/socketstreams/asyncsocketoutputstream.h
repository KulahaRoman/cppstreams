#pragma once
#include "../iasyncoutputstream.h"
#include "abstracts/abstractasyncsocketoutputstream.h"

class AsyncSocketOutputStream : private AbstractAsyncSocketOutputStream,
                                public IAsyncOutputStream {
 public:
  AsyncSocketOutputStream(boost::asio::ip::tcp::socket&& socket);

  void Write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& callback) override;
  void Flush(const std::function<void(uint64_t)>& callback) override;
};
