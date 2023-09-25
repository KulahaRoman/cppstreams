#include "socketinputstream.h"

namespace CppStreams {
SocketInputStream::SocketInputStream(boost::asio::ip::tcp::socket&& socket)
    : AbstractSocketStream(std::move(socket)) {}

uint64_t SocketInputStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

void SocketInputStream::Read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  read(data, size, onSuccess, onFailure);
}

uint64_t SocketInputStream::Skip(uint64_t nBytes) { return skip(nBytes); }

void SocketInputStream::Skip(
    uint64_t size, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  skip(size, onSuccess, onFailure);
}

uint64_t SocketInputStream::Available() { return available(); }
}  // namespace CppStreams
