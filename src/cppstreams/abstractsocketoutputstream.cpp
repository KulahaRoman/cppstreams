#include "abstractsocketoutputstream.h"

namespace CppStreams {
uint64_t AbstractSocketOutputStream::Write(const unsigned char* data,
                                           uint64_t size) {
  if (!size) {
    return size;
  }

  uint64_t bytesWritten = 0ull;
  try {
    bytesWritten = boost::asio::write(
        socket, boost::asio::const_buffer(data, static_cast<size_t>(size)));
  } catch (...) {
    throw std::runtime_error("Failed to write bytes (IO error).");
  }
  return bytesWritten;
}

void AbstractSocketOutputStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  if (!size) {
    if (onSuccess) {
      onSuccess(size);
    }
    return;
  }

  boost::asio::async_write(
      socket, boost::asio::const_buffer(data, static_cast<size_t>(size)),
      [this, onSuccess, onFailure, self = shared_from_this()](
          const auto& error, const auto& bytesWritten) {
        if (error) {
          if (onFailure) {
            onFailure(std::runtime_error("Failed to write bytes (IO error)."));
          }
          return;
        }

        if (onSuccess) {
          onSuccess(bytesWritten);
        }
      });
}

uint64_t AbstractSocketOutputStream::Flush() {
  throw std::runtime_error(
      "Unsupported stream method (Flush() for non-buffered stream).");
  return 0ull;
}

void AbstractSocketOutputStream::Flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  if (onFailure) {
    onFailure(std::runtime_error(
        "Unsupported stream method (Flush() for non-bufered stream)."));
  }
}
}  // namespace CppStreams
