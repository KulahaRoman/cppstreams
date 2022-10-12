#pragma once
#include "../iinputstream.h"
#include "abstracts/abstractsocketinputstream.h"

class SocketInputStream : private AbstractSocketInputStream,
                          public IInputStream {
 public:
  SocketInputStream(boost::asio::ip::tcp::socket&& socket);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  uint64_t Skip(uint64_t size) override;
  uint64_t Available() override;
};
