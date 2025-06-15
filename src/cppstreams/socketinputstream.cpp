#include "socketinputstream.h"

namespace CppStreams {
SocketInputStream::SocketInputStream(boost::asio::ip::tcp::socket&& socket)
    : AbstractSocketStream(std::move(socket)) {}

uint64_t SocketInputStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

uint64_t SocketInputStream::Skip(uint64_t nBytes) { return skip(nBytes); }

uint64_t SocketInputStream::Available() { return available(); }
}  // namespace CppStreams
