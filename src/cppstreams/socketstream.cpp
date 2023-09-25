#include "socketstream.h"

namespace CppStreams {
SocketStream::SocketStream(boost::asio::ip::tcp::socket&& socket)
    : AbstractSocketStream(std::move(socket)) {}

uint64_t SocketStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

void SocketStream::Read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  read(data, size, onSuccess, onFailure);
}

uint64_t SocketStream::Skip(uint64_t nBytes) { return skip(nBytes); }

void SocketStream::Skip(
    uint64_t size, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  skip(size, onSuccess, onFailure);
}

uint64_t SocketStream::Available() { return available(); }

uint64_t SocketStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

void SocketStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  write(data, size, onSuccess, onFailure);
}

uint64_t SocketStream::Flush() { return flush(); }

void SocketStream::Flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  flush(onSuccess, onFailure);
}
}  // namespace CppStreams
