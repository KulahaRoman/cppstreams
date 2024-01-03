#include "abstractfileoutputstream.h"

namespace CppStreams {
AbstractFileOutputStream::AbstractFileOutputStream() : ppos(0) {}

uint64_t AbstractFileOutputStream::Write(const unsigned char* data,
                                         uint64_t size) {
  if (!size) {
    return size;
  }

  file.seekp(ppos, std::ios::beg);

  try {
    file.write(reinterpret_cast<const char*>(data), size);
  } catch (...) {
    throw std::runtime_error("Failed to write bytes (IO error).");
  }

  ppos += size;

  return size;
}

void AbstractFileOutputStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  CppUtils::ThreadPool::AcceptTask(
      [this, data, size, onSuccess, onFailure, self = shared_from_this()] {
        try {
          auto result = AbstractFileOutputStream::Write(data, size);
          if (onSuccess) {
            onSuccess(result);
          }
        } catch (const std::exception& ex) {
          if (onFailure) {
            onFailure(ex);
          }
        }
      });
}

uint64_t AbstractFileOutputStream::Flush() {
  throw std::runtime_error(
      "Unsupported stream method (Flush() for non-bufered stream).");
  return 0ull;
}

void AbstractFileOutputStream::Flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  CppUtils::ThreadPool::AcceptTask(
      [this, onSuccess, onFailure, self = shared_from_this()] {
        try {
          auto result = AbstractFileOutputStream::Flush();
          if (onSuccess) {
            onSuccess(result);
          }
        } catch (const std::exception& ex) {
          if (onFailure) {
            onFailure(ex);
          }
        }
      });
}
}  // namespace CppStreams
