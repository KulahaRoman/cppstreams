#include "abstractasyncsocketoutputstream.h"

void AbstractAsyncSocketOutputStream::write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& callback) {
  if (!size) {
    ThreadPool::AcceptTask([callback, size] { callback(size); });
    return;
  }

  boost::asio::async_write(
      socket, boost::asio::const_buffer(data, static_cast<size_t>(size)),
      [this, callback](const auto& error, const auto& bytesWritten) {
        if (error) {
          ThreadPool::AcceptTask([] {
            throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
                L"Failed to write bytes (IO error)."
#else
                "Failed to write bytes (IO error)."
#endif
            );
          });
          return;
        }
        if (callback) {
          ThreadPool::AcceptTask(callback, bytesWritten);
        }
      });
}

void AbstractAsyncSocketOutputStream::flush(
    const std::function<void(uint64_t)>& callback) {
  ThreadPool::AcceptTask([] {
    throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
        L"Unsupported stream method (Flush() for non-bufered stream)."
#else
        "Unsupported stream method (Flush() for non-bufered stream)."
#endif
    );
  });
}
