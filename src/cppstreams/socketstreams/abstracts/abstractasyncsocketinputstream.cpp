#include "abstractasyncsocketinputstream.h"

void AbstractAsyncSocketInputStream::read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& callback) {
  if (!size) {
    ThreadPool::AcceptTask([callback, size] { callback(size); });
    return;
  }

  auto bytesAvailable = available();
  if (bytesAvailable < size) {
    ThreadPool::AcceptTask([] {
      throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
          L"Failed to read bytes (insufficient bytes available)."
#else
          "Failed to read bytes (insufficient bytes available)."
#endif
      );
    });
    return;
  }

  auto tempBuffer =
      std::make_shared<std::vector<unsigned char>>(static_cast<size_t>(size));

  boost::asio::async_read(
      socket, boost::asio::buffer(tempBuffer->data(), tempBuffer->size()),
      [this, tempBuffer, data, callback](const auto& error,
                                         const auto& bytesRead) {
        if (error) {
          ThreadPool::AcceptTask([] {
            throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
                L"Failed to read bytes (IO error)."
#else
                "Failed to read bytes (IO error)."
#endif
            );
          });
          return;
        }

        std::copy(tempBuffer->data(), tempBuffer->data() + tempBuffer->size(),
                  data);

        if (callback) {
          ThreadPool::AcceptTask(callback, bytesRead);
        }
      });
}

uint64_t AbstractAsyncSocketInputStream::available() {
  return static_cast<uint64_t>(socket.available());
}

void AbstractAsyncSocketInputStream::skip(
    uint64_t nBytes, const std::function<void(uint64_t)>& callback) {
  if (!nBytes) {
    ThreadPool::AcceptTask([callback, nBytes] { callback(nBytes); });
    return;
  }

  auto bytesAvailable = available();
  if (bytesAvailable < nBytes) {
    ThreadPool::AcceptTask([] {
      throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
          L"Failed to skip bytes (insufficient bytes available)."
#else
          "Failed to skip bytes (insufficient bytes available)."
#endif
      );
    });
    return;
  }

  auto tempBuffer =
      std::make_shared<std::vector<unsigned char>>(static_cast<size_t>(nBytes));

  boost::asio::async_read(
      socket, boost::asio::buffer(tempBuffer->data(), tempBuffer->size()),
      [this, callback](const auto& error, const auto& bytesRead) {
        if (error) {
          ThreadPool::AcceptTask([] {
            throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
                L"Failed to skip bytes (IO error)."
#else
                "Failed to skip bytes (IO error)."
#endif
            );
          });
          return;
        }
        if (callback) {
          ThreadPool::AcceptTask(callback, bytesRead);
        }
      });
}
