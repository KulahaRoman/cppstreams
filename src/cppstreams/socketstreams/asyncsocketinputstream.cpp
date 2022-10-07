#include "asyncsocketinputstream.h"

AsyncSocketInputStream::AsyncSocketInputStream(
    boost::asio::ip::tcp::socket&& socket)
    : AbstractSocketStream(std::move(socket)) {}

void AsyncSocketInputStream::Read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& callback) {
  read(data, size, callback);
}

uint64_t AsyncSocketInputStream::Available() { return available(); }

void AsyncSocketInputStream::Skip(
    uint64_t nBytes, const std::function<void(uint64_t)>& callback) {
  skip(nBytes, callback);
}
