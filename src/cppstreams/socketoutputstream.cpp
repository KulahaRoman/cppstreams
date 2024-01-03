#include "socketoutputstream.h"

namespace CppStreams {
SocketOutputStream::SocketOutputStream(boost::asio::ip::tcp::socket&& socket)
    : AbstractSocketStream(std::move(socket)) {}

uint64_t SocketOutputStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

void SocketOutputStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  write(
      data, size,
      [onSuccess, self = shared_from_this()](auto writtenBytes) {
        if (onSuccess) {
          onSuccess(writtenBytes);
        }
      },
      [onFailure](const auto& exc) {
        if (onFailure) {
          onFailure(exc);
        }
      });
}

uint64_t SocketOutputStream::Flush() { return flush(); }

void SocketOutputStream::Flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  flush(
      [onSuccess, self = shared_from_this()](auto flushedBytes) {
        if (onSuccess) {
          onSuccess(flushedBytes);
        }
      },
      [onFailure](const auto& exc) {
        if (onFailure) {
          onFailure(exc);
        }
      });
}
}  // namespace CppStreams
