#include "bufferedoutputstream.h"

namespace CppStreams {
BufferedOutputStream::BufferedOutputStream(
    const std::shared_ptr<OutputStream>& stream, uint64_t bufferSize)
    : AbstractBufferedOutputStream(stream, bufferSize) {}

uint64_t BufferedOutputStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

void BufferedOutputStream::Write(
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

uint64_t BufferedOutputStream::Flush() { return flush(); }

void BufferedOutputStream::Flush(
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
