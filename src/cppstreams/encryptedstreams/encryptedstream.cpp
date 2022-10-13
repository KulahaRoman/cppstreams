#include "encryptedstream.h"

EncryptedStream::EncryptedStream(const std::shared_ptr<Encryptor>& encryptor,
                                 const std::shared_ptr<Stream>& stream)
    : AbstractEncryptedStream(encryptor),
      EncryptedInputStream(stream, encryptor->GetBlockSize()),
      EncryptedOutputStream(stream, encryptor->GetBlockSize()) {}

uint64_t EncryptedStream::Read(unsigned char* data, uint64_t size) {
  return EncryptedInputStream::Read(data, size);
}

void EncryptedStream::Read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  EncryptedInputStream::Read(data, size, onSuccess, onFailure);
}

uint64_t EncryptedStream::Skip(uint64_t nBytes) {
  return EncryptedInputStream::Skip(nBytes);
}

void EncryptedStream::Skip(
    uint64_t size, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  EncryptedInputStream::Skip(size, onSuccess, onFailure);
}

uint64_t EncryptedStream::Available() {
  return EncryptedInputStream::Available();
}

uint64_t EncryptedStream::Write(const unsigned char* data,
                                const uint64_t size) {
  return EncryptedOutputStream::Write(data, size);
}

void EncryptedStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  EncryptedOutputStream::Write(data, size, onSuccess, onFailure);
}

uint64_t EncryptedStream::Flush() { return EncryptedOutputStream::Flush(); }

void EncryptedStream::Flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  EncryptedOutputStream::Flush(onSuccess, onFailure);
}