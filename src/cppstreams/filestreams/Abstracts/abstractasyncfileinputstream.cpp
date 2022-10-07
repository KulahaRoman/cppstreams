#include "abstractasyncfileinputstream.h"

void AbstractAsyncFileInputStream::read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& callback) {
  ThreadPool::AcceptTask([this, data, size, callback] {
    auto result = AbstractFileInputStream::read(data, size);
    if (callback) {
      callback(result);
    }
  });
}

void AbstractAsyncFileInputStream::skip(
    uint64_t nBytes, const std::function<void(uint64_t)>& callback) {
  ThreadPool::AcceptTask([this, nBytes, callback] {
    auto result = AbstractFileInputStream::skip(nBytes);
    if (callback) {
      callback(result);
    }
  });
}
