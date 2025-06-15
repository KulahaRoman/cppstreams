#pragma once
#include "abstractsocketinputstream.h"
#include "abstractsocketoutputstream.h"
#include "stream.h"

namespace CppStreams {
class SocketStream : private AbstractSocketInputStream,
                     private AbstractSocketOutputStream,
                     public Stream {
 public:
  SocketStream(boost::asio::ip::tcp::socket&& socket);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  uint64_t Skip(uint64_t size) override;
  uint64_t Available() override;
  uint64_t Write(const unsigned char* data, uint64_t size) override;
  uint64_t Flush() override;
};
}  // namespace CppStreams
