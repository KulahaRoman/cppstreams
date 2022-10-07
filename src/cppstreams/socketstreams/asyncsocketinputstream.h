#pragma once
#include "../iasyncinputstream.h"
#include "abstracts/abstractasyncsocketinputstream.h"

class AsyncSocketInputStream : private AbstractAsyncSocketInputStream,
                               public IAsyncInputStream {
 public:
  AsyncSocketInputStream(boost::asio::ip::tcp::socket&& socket);

  void Read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& callback) override;
  uint64_t Available() override;
  void Skip(uint64_t nBytes,
            const std::function<void(uint64_t)>& callback) override;
};
