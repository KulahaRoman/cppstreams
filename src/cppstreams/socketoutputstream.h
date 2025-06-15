#pragma once
#include "abstractsocketoutputstream.h"
#include "outputstream.h"

namespace CppStreams {
class SocketOutputStream : private AbstractSocketOutputStream,
                           public OutputStream {
 public:
  SocketOutputStream(boost::asio::ip::tcp::socket&& socket);

  uint64_t Write(const unsigned char* data, uint64_t size) override;
  uint64_t Flush() override;
};
}  // namespace CppStreams
