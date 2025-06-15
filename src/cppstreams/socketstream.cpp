#include "socketstream.h"

namespace CppStreams {
SocketStream::SocketStream(boost::asio::ip::tcp::socket&& socket)
    : AbstractSocketStream(std::move(socket)) {}

uint64_t SocketStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

uint64_t SocketStream::Skip(uint64_t nBytes) { return skip(nBytes); }

uint64_t SocketStream::Available() { return available(); }

uint64_t SocketStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

uint64_t SocketStream::Flush() { return flush(); }
}  // namespace CppStreams
