#include "asyncencryptedstream.h"

AsyncEncryptedStream::AsyncEncryptedStream(
    const std::shared_ptr<IEncryptor>& encryptor,
    const std::shared_ptr<IAsyncStream>& stream)
    : AbstractEncryptedStream(encryptor),
      AsyncEncryptedInputStream(stream, encryptor->GetBlockSize()),
      AsyncEncryptedOutputStream(stream, encryptor->GetBlockSize()) {}

void AsyncEncryptedStream::Read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  AsyncEncryptedInputStream::Read(data, size, onSuccess, onFailure);
}

void AsyncEncryptedStream::Skip(
    uint64_t nBytes, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  AsyncEncryptedInputStream::Skip(nBytes, onSuccess, onFailure);
}

uint64_t AsyncEncryptedStream::Available() {
  return AsyncEncryptedInputStream::Available();
}

void AsyncEncryptedStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  AsyncEncryptedOutputStream::Write(data, size, onSuccess, onFailure);
}

void AsyncEncryptedStream::Flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  AsyncEncryptedOutputStream::Flush(onSuccess, onFailure);
}
