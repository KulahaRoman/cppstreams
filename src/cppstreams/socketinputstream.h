#pragma once
#include "abstractsocketinputstream.h"
#include "inputstream.h"

namespace CppStreams {
class SocketInputStream : private AbstractSocketInputStream,
                          public InputStream {
 public:
  SocketInputStream(boost::asio::ip::tcp::socket&& socket);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  uint64_t Skip(uint64_t size) override;
  uint64_t Available() override;
};
}  // namespace CppStreams
