#include "socketoutputstream.h"

namespace CppStreams {
SocketOutputStream::SocketOutputStream(boost::asio::ip::tcp::socket&& socket)
    : AbstractSocketStream(std::move(socket)) {}
}  // namespace CppStreams
