#pragma once
#include "../ioutputstream.h"
#include "abstracts/abstractsocketoutputstream.h"

class SocketOutputStream : private AbstractSocketOutputStream,
                           public IOutputStream {
 public:
  SocketOutputStream(boost::asio::ip::tcp::socket&& socket);

  uint64_t Write(const unsigned char* data, uint64_t size) override;
  uint64_t Flush() override;
};
