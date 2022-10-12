#pragma once
#include "../istream.h"
#include "abstracts/abstractsocketinputstream.h"
#include "abstracts/abstractsocketoutputstream.h"

class SocketStream : private AbstractSocketInputStream,
                     private AbstractSocketOutputStream,
                     public IStream {
 public:
  SocketStream(boost::asio::ip::tcp::socket&& socket);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  uint64_t Skip(uint64_t size) override;
  uint64_t Available() override;
  uint64_t Write(const unsigned char* data, uint64_t size) override;
  uint64_t Flush() override;
};
