#include "abstractsocketoutputstream.h"

uint64_t AbstractSocketOutputStream::write(const unsigned char* data,
                                           uint64_t size) {
  if (!size) {
    return size;
  }

  uint64_t bytesWritten = 0ull;
  try {
    bytesWritten = boost::asio::write(
        socket, boost::asio::const_buffer(data, static_cast<size_t>(size)));
  } catch (...) {
    throw RuntimeException("Failed to write bytes (IO error).");
  }
  return bytesWritten;
}

void AbstractSocketOutputStream::write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  if (!size) {
    ThreadPool::AcceptTask([onSuccess, size] {
      if (onSuccess) {
        onSuccess(size);
      }
    });
    return;
  }

  boost::asio::async_write(
      socket, boost::asio::const_buffer(data, static_cast<size_t>(size)),
      [this, onSuccess, onFailure](const auto& error,
                                   const auto& bytesWritten) {
        if (error) {
          ThreadPool::AcceptTask([onFailure] {
            if (onFailure) {
              onFailure(RuntimeException("Failed to write bytes (IO error)."));
            }
          });
          return;
        }

        ThreadPool::AcceptTask([onSuccess, bytesWritten] {
          if (onSuccess) {
            onSuccess(bytesWritten);
          }
        });
      });
}

uint64_t AbstractSocketOutputStream::flush() {
  throw RuntimeException(
      "Unsupported stream method (Flush() for non-bufered stream).");
  return 0ull;
}

void AbstractSocketOutputStream::flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  ThreadPool::AcceptTask([onFailure] {
    if (onFailure) {
      onFailure(RuntimeException(
          "Unsupported stream method (Flush() for non-bufered stream)."));
    }
  });
}
