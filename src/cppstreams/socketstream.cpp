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

uint64_t SocketStream::Skip(uint64_t nBytes) { return skip(nBytes); }

void SocketStream::Skip(
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

uint64_t SocketStream::Available() { return available(); }

uint64_t SocketStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

void SocketStream::Write(
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

uint64_t SocketStream::Flush() { return flush(); }

void SocketStream::Flush(
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
