#pragma once
#include "abstractsocketinputstream.h"

namespace CppStreams {
class SocketInputStream : public AbstractSocketInputStream {
 public:
  SocketInputStream(boost::asio::ip::tcp::socket&& socket);
};
}  // namespace CppStreams
