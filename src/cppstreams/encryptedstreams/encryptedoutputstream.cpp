#include "encryptedoutputstream.h"

EncryptedOutputStream::EncryptedOutputStream(
    const std::shared_ptr<IOutputStream>& stream, uint64_t bufferSize)
    : BufferedOutputStream(stream, bufferSize) {}

EncryptedOutputStream::EncryptedOutputStream(
    const std::shared_ptr<IEncryptor>& encryptor,
    const std::shared_ptr<IOutputStream>& stream)
    : BufferedOutputStream(stream, encryptor->GetBlockSize()),
      AbstractEncryptedStream(encryptor) {}

void EncryptedOutputStream::processWriteBuffer() {
  writeBuffer = encryptor->Encrypt(writeBuffer);
}
