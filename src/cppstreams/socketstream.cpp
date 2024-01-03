#include "socketstream.h"

namespace CppStreams {
SocketStream::SocketStream(boost::asio::ip::tcp::socket&& socket)
    : AbstractSocketStream(std::move(socket)) {}

uint64_t SocketStream::Read(unsigned char* data, uint64_t size) {
  return AbstractSocketInputStream::Read(data, size);
}

void SocketStream::Read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  AbstractSocketInputStream::Read(data, size, onSuccess, onFailure);
}

uint64_t SocketStream::Skip(uint64_t nBytes) {
  return AbstractSocketInputStream::Skip(nBytes);
}

void SocketStream::Skip(
    uint64_t size, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  AbstractSocketInputStream::Skip(size, onSuccess, onFailure);
}

uint64_t SocketStream::Available() {
  return AbstractSocketInputStream::Available();
}

uint64_t SocketStream::Write(const unsigned char* data, uint64_t size) {
  return AbstractSocketOutputStream::Write(data, size);
}

void SocketStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  AbstractSocketOutputStream::Write(data, size, onSuccess, onFailure);
}

uint64_t SocketStream::Flush() { return AbstractSocketOutputStream::Flush(); }

void SocketStream::Flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  AbstractSocketOutputStream::Flush(onSuccess, onFailure);
}
}  // namespace CppStreams
