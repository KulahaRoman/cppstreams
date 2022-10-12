#include "abstractasyncfileinputstream.h"

void AbstractAsyncFileInputStream::read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  ThreadPool::AcceptTask([this, data, size, onSuccess, onFailure] {
    try {
      auto result = AbstractFileInputStream::read(data, size);
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

void AbstractAsyncFileInputStream::skip(
    uint64_t size, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  ThreadPool::AcceptTask([this, size, onSuccess, onFailure] {
    try {
      auto result = AbstractFileInputStream::skip(size);
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
