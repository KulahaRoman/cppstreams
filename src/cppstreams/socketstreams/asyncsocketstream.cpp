#include "asyncsocketstream.h"

AsyncSocketStream::AsyncSocketStream(boost::asio::ip::tcp::socket&& socket)
    : AbstractSocketStream(std::move(socket)) {}

void AsyncSocketStream::Read(unsigned char* data, uint64_t size,
                             const std::function<void(uint64_t)>& callback) {
  read(data, size, callback);
}

void AsyncSocketStream::Write(const unsigned char* data, uint64_t size,
                              const std::function<void(uint64_t)>& callback) {
  write(data, size, callback);
}

void AsyncSocketStream::Flush(const std::function<void(uint64_t)>& callback) {
  flush(callback);
}

uint64_t AsyncSocketStream::Available() { return available(); }

void AsyncSocketStream::Skip(uint64_t nBytes,
                             const std::function<void(uint64_t)>& callback) {
  skip(nBytes, callback);
}
