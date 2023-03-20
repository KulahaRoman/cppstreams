#include "abstractsocketstream.h"

AbstractSocketStream::AbstractSocketStream() : socket(0) {}

AbstractSocketStream::AbstractSocketStream(
    boost::asio::ip::tcp::socket&& socket)
    : socket(std::move(socket)) {}

AbstractSocketStream::~AbstractSocketStream() {
  if (socket.is_open()) {
    try {
      socket.shutdown(boost::asio::socket_base::shutdown_both);
      socket.close();
    } catch (...) {
      // suppress
    }
  }
}
