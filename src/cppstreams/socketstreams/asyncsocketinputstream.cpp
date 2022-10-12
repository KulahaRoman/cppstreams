#include "asyncsocketinputstream.h"

AsyncSocketInputStream::AsyncSocketInputStream(
    boost::asio::ip::tcp::socket&& socket)
    : AbstractSocketStream(std::move(socket)) {}

void AsyncSocketInputStream::Read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  read(data, size, onSuccess, onFailure);
}

void AsyncSocketInputStream::Skip(
    uint64_t size, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  skip(size, onSuccess, onFailure);
}

uint64_t AsyncSocketInputStream::Available() { return available(); }
