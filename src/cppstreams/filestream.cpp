#include "filestream.h"

namespace CppStreams {
FileStream::FileStream(const std::string& file, bool binary)
    : AbstractFileStream(
          file, std::ios::in | std::ios::out |
                    (binary ? std::ios::binary : std::ios::openmode(0))) {}

uint64_t FileStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

void FileStream::Read(
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

uint64_t FileStream::Skip(uint64_t nBytes) { return skip(nBytes); }

void FileStream::Skip(
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

uint64_t FileStream::Available() { return available(); }

uint64_t FileStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

void FileStream::Write(
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

uint64_t FileStream::Flush() { return flush(); }

void FileStream::Flush(
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
