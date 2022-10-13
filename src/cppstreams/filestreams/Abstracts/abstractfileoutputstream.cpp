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
    throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
        L"Failed to write bytes (IO error)."
#else
        "Failed to write bytes (IO error)."
#endif
    );
  }

  ppos += size;

  return size;
}

void AbstractFileOutputStream::write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  ThreadPool::AcceptTask([this, data, size, onSuccess, onFailure] {
    try {
      auto result = AbstractFileOutputStream::write(data, size);
      if (onSuccess) {
        onSuccess(result);
      }
    } catch (const Exception& ex) {
      if (onFailure) {
        onFailure(ex);
      }
    }
  });
}

uint64_t AbstractFileOutputStream::flush() {
  throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
      L"Unsupported stream method (Flush() for non-bufered stream)."
#else
      "Unsupported stream method (Flush() for non-bufered stream)."
#endif
  );
  return 0ull;
}

void AbstractFileOutputStream::flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  ThreadPool::AcceptTask([this, onSuccess, onFailure] {
    try {
      auto result = AbstractFileOutputStream::flush();
      if (onSuccess) {
        onSuccess(result);
      }
    } catch (const Exception& ex) {
      if (onFailure) {
        onFailure(ex);
      }
    }
  });
}
