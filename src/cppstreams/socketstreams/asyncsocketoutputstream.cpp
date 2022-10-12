#include "asyncsocketoutputstream.h"

AsyncSocketOutputStream::AsyncSocketOutputStream(
    boost::asio::ip::tcp::socket&& socket)
    : AbstractSocketStream(std::move(socket)) {}

void AsyncSocketOutputStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  write(data, size, onSuccess, onFailure);
}

void AsyncSocketOutputStream::Flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  flush(onSuccess, onFailure);
}
