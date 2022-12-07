#include "abstractfileoutputstream.h"

AbstractFileOutputStream::AbstractFileOutputStream() : ppos(0) {}

uint64_t AbstractFileOutputStream::write(const unsigned char* data,
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

void AbstractFileOutputStream::write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  ThreadPool::AcceptTask([this, data, size, onSuccess, onFailure] {
    try {
      auto result = AbstractFileOutputStream::write(data, size);
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

uint64_t AbstractFileOutputStream::flush() {
  throw std::runtime_error(
      "Unsupported stream method (Flush() for non-bufered stream).");
  return 0ull;
}

void AbstractFileOutputStream::flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  ThreadPool::AcceptTask([this, onSuccess, onFailure] {
    try {
      auto result = AbstractFileOutputStream::flush();
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
