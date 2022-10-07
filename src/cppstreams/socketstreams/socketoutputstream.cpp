#include "socketoutputstream.h"

SocketOutputStream::SocketOutputStream(boost::asio::ip::tcp::socket&& socket)
    : AbstractSocketStream(std::move(socket)) {}

uint64_t SocketOutputStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

uint64_t SocketOutputStream::Flush() { return flush(); }
