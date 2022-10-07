#include "asyncencryptedstream.h"

AsyncEncryptedStream::AsyncEncryptedStream(
    const std::shared_ptr<IEncryptor>& encryptor,
    const std::shared_ptr<IAsyncStream>& stream)
    : AbstractEncryptedStream(encryptor),
      AsyncEncryptedInputStream(stream, encryptor->GetBlockSize()),
      AsyncEncryptedOutputStream(stream, encryptor->GetBlockSize()) {}

void AsyncEncryptedStream::Read(unsigned char* data, uint64_t size,
                                const std::function<void(uint64_t)>& callback) {
  AsyncEncryptedInputStream::Read(data, size, callback);
}

uint64_t AsyncEncryptedStream::Available() {
  return AsyncEncryptedInputStream::Available();
}

void AsyncEncryptedStream::Skip(uint64_t nBytes,
                                const std::function<void(uint64_t)>& callback) {
  AsyncEncryptedInputStream::Skip(nBytes, callback);
}

void AsyncEncryptedStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& callback) {
  AsyncEncryptedOutputStream::Write(data, size, callback);
}

void AsyncEncryptedStream::Flush(
    const std::function<void(uint64_t)>& callback) {
  AsyncEncryptedOutputStream::Flush(callback);
}
