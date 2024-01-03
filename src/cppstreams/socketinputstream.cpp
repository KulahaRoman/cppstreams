#include "socketinputstream.h"

namespace CppStreams {
SocketInputStream::SocketInputStream(boost::asio::ip::tcp::socket&& socket)
    : AbstractSocketStream(std::move(socket)) {}
}  // namespace CppStreams
