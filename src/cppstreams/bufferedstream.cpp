#include "bufferedstream.h"

namespace CppStreams {
BufferedStream::BufferedStream(const std::shared_ptr<Stream>& stream,
                               uint64_t bufferSize)
    : AbstractBufferedInputStream(stream, bufferSize),
      AbstractBufferedOutputStream(stream, bufferSize) {}

uint64_t BufferedStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

void BufferedStream::Read(
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

uint64_t BufferedStream::Skip(uint64_t nBytes) { return skip(nBytes); }

void BufferedStream::Skip(
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

uint64_t BufferedStream::Available() { return available(); }

uint64_t BufferedStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

void BufferedStream::Write(
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

uint64_t BufferedStream::Flush() { return flush(); }

void BufferedStream::Flush(
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
