#include "abstractsocketinputstream.h"

uint64_t AbstractSocketInputStream::read(unsigned char* data, uint64_t size) {
  if (!size) {
    return size;
  }

  uint64_t bytesAvailable = available();
  if (bytesAvailable < size) {
    throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
        L"Failed to read bytes (insufficient bytes available)."
#else
        "Failed to read bytes (insufficient bytes available)."
#endif
    );
  }

  uint64_t bytesRead = 0ull;

  auto tempBuffer =
      std::make_shared<std::vector<unsigned char>>(static_cast<size_t>(size));

  try {
    bytesRead = boost::asio::read(
        socket, boost::asio::buffer(tempBuffer->data(), tempBuffer->size()));
  } catch (...) {
    throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
        L"Failed to read bytes (IO error)."
#else
        "Failed to read bytes (IO error)."
#endif
    );
  }

  std::copy(tempBuffer->data(), tempBuffer->data() + tempBuffer->size(), data);

  return bytesRead;
}

void AbstractSocketInputStream::read(
    unsigned char* data, uint64_t size,
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

  auto bytesAvailable = available();
  if (bytesAvailable < size) {
    ThreadPool::AcceptTask([onFailure] {
      if (onFailure) {
        onFailure(RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
            L"Failed to read bytes (insufficient bytes available)."
#else
            "Failed to read bytes (insufficient bytes available)."
#endif
            ));
      }
    });
    return;
  }

  auto tempBuffer =
      std::make_shared<std::vector<unsigned char>>(static_cast<size_t>(size));

  boost::asio::async_read(
      socket, boost::asio::buffer(tempBuffer->data(), tempBuffer->size()),
      [this, tempBuffer, data, onSuccess, onFailure](const auto& error,
                                                     const auto& bytesRead) {
        if (error) {
          ThreadPool::AcceptTask([onFailure] {
            if (onFailure) {
              onFailure(RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
                  L"Failed to read bytes (IO error)."
#else
                  "Failed to read bytes (IO error)."
#endif
                  ));
            }
          });
          return;
        }

        std::copy(tempBuffer->data(), tempBuffer->data() + tempBuffer->size(),
                  data);

        ThreadPool::AcceptTask([onSuccess, bytesRead] {
          if (onSuccess) {
            onSuccess(bytesRead);
          }
        });
      });
}

uint64_t AbstractSocketInputStream::skip(uint64_t nBytes) {
  if (!nBytes) {
    return nBytes;
  }

  uint64_t bytesAvailable = available();
  if (bytesAvailable < nBytes) {
    throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
        L"Failed to skip bytes (insufficient bytes available)."
#else
        "Failed to skip bytes (insufficient bytes available)."
#endif
    );
  }

  uint64_t bytesSkipped = 0ull;

  std::vector<unsigned char> tempBuffer(static_cast<size_t>(nBytes));

  try {
    bytesSkipped = boost::asio::read(
        socket, boost::asio::buffer(tempBuffer.data(), tempBuffer.size()));
  } catch (...) {
    throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
        L"Failed to skip bytes (IO error)."
#else
        "Failed to skip bytes (IO error)."
#endif
    );
  }

  return bytesSkipped;
}

void AbstractSocketInputStream::skip(
    uint64_t size, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  if (!size) {
    ThreadPool::AcceptTask([onSuccess, size] {
      if (onSuccess) {
        onSuccess(size);
      }
    });
    return;
  }

  auto bytesAvailable = available();
  if (bytesAvailable < size) {
    ThreadPool::AcceptTask([onFailure] {
      if (onFailure) {
        onFailure(RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
            L"Failed to skip bytes (insufficient bytes available)."
#else
            "Failed to skip bytes (insufficient bytes available)."
#endif
            ));
      }
    });
    return;
  }

  auto tempBuffer =
      std::make_shared<std::vector<unsigned char>>(static_cast<size_t>(size));

  boost::asio::async_read(
      socket, boost::asio::buffer(tempBuffer->data(), tempBuffer->size()),
      [this, onSuccess, onFailure](const auto& error, const auto& bytesRead) {
        if (error) {
          ThreadPool::AcceptTask([onFailure] {
            if (onFailure) {
              onFailure(RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
                  L"Failed to skip bytes (IO error)."
#else
                  "Failed to skip bytes (IO error)."
#endif
                  ));
            }
          });
          return;
        }

        ThreadPool::AcceptTask([onSuccess, bytesRead] {
          if (onSuccess) {
            onSuccess(bytesRead);
          }
        });
      });
}

uint64_t AbstractSocketInputStream::available() {
  return static_cast<uint64_t>(socket.available());
}