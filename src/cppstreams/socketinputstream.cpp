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
  read(
      data, size,
      [onSuccess, self = shared_from_this()](auto readBytes) {
        if (onSuccess) {
          onSuccess(readBytes);
        }
      },
      [onFailure](const auto& exc) {
        if (onFailure) {
          onFailure(exc);
        }
      });
}

uint64_t SocketInputStream::Skip(uint64_t nBytes) { return skip(nBytes); }

void SocketInputStream::Skip(
    uint64_t size, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  skip(
      size,
      [onSuccess, self = shared_from_this()](auto skippedBytes) {
        if (onSuccess) {
          onSuccess(skippedBytes);
        }
      },
      [onFailure](const auto& exc) {
        if (onFailure) {
          onFailure(exc);
        }
      });
}

uint64_t SocketInputStream::Available() { return available(); }
}  // namespace CppStreams
