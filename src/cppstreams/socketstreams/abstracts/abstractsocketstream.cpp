#include "abstractsocketstream.h"

AbstractSocketStream::AbstractSocketStream() : socket(0) {}

AbstractSocketStream::AbstractSocketStream(
    boost::asio::ip::tcp::socket&& socket)
    : socket(std::move(socket)) {}

AbstractSocketStream::~AbstractSocketStream() { socket.close(); }
