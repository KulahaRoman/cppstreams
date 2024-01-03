#pragma once
#include "abstractsocketoutputstream.h"

namespace CppStreams {
class SocketOutputStream : public AbstractSocketOutputStream {
 public:
  SocketOutputStream(boost::asio::ip::tcp::socket&& socket);
};
}  // namespace CppStreams
