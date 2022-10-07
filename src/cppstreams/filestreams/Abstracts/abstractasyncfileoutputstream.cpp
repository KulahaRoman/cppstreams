#include "abstractasyncfileoutputstream.h"

void AbstractAsyncFileOutputStream::write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& callback) {
  ThreadPool::AcceptTask([this, data, size, callback] {
    auto result = AbstractFileOutputStream::write(data, size);
    if (callback) {
      callback(result);
    }
  });
}

void AbstractAsyncFileOutputStream::flush(
    const std::function<void(uint64_t)>& callback) {
  ThreadPool::AcceptTask([this, callback] {
    auto result = AbstractFileOutputStream::flush();
    if (callback) {
      callback(result);
    }
  });
}
