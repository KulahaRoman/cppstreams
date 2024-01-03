#include "bufferedinputstream.h"

namespace CppStreams {
BufferedInputStream::BufferedInputStream(
    const std::shared_ptr<InputStream>& stream, uint64_t bufferSize)
    : AbstractBufferedInputStream(stream, bufferSize) {}

uint64_t BufferedInputStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

void BufferedInputStream::Read(
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

uint64_t BufferedInputStream::Skip(uint64_t nBytes) { return skip(nBytes); }

void BufferedInputStream::Skip(
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

uint64_t BufferedInputStream::Available() { return available(); }
}  // namespace CppStreams
