#include "encryptedstream.h"

EncryptedStream::EncryptedStream(const std::shared_ptr<IEncryptor>& encryptor,
                                 const std::shared_ptr<IStream>& stream)
    : AbstractEncryptedStream(encryptor),
      EncryptedInputStream(stream, encryptor->GetBlockSize()),
      EncryptedOutputStream(stream, encryptor->GetBlockSize()) {}

uint64_t EncryptedStream::Read(unsigned char* data, uint64_t size) {
  return EncryptedInputStream::Read(data, size);
}

uint64_t EncryptedStream::Skip(uint64_t nBytes) {
  return EncryptedInputStream::Skip(nBytes);
}

uint64_t EncryptedStream::Available() {
  return EncryptedInputStream::Available();
}

uint64_t EncryptedStream::Write(const unsigned char* data,
                                const uint64_t size) {
  return EncryptedOutputStream::Write(data, size);
}

uint64_t EncryptedStream::Flush() { return EncryptedOutputStream::Flush(); }
