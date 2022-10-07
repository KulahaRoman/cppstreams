#include "encryptedinputstream.h"

EncryptedInputStream::EncryptedInputStream(
    const std::shared_ptr<IInputStream>& stream, uint64_t bufferSize)
    : BufferedInputStream(stream, bufferSize) {}

EncryptedInputStream::EncryptedInputStream(
    const std::shared_ptr<IEncryptor>& encryptor,
    const std::shared_ptr<IInputStream>& stream)
    : BufferedInputStream(stream, encryptor->GetBlockSize()),
      AbstractEncryptedStream(encryptor) {}

void EncryptedInputStream::processReadBuffer() {
  readBuffer = encryptor->Decrypt(readBuffer);
}
