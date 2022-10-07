#include "asyncencryptedoutputstream.h"

AsyncEncryptedOutputStream::AsyncEncryptedOutputStream(
    const std::shared_ptr<IAsyncOutputStream>& stream, uint64_t bufferSize)
    : AsyncBufferedOutputStream(stream, bufferSize) {}

AsyncEncryptedOutputStream::AsyncEncryptedOutputStream(
    const std::shared_ptr<IEncryptor>& encryptor,
    const std::shared_ptr<IAsyncOutputStream>& stream)
    : AsyncBufferedOutputStream(stream, encryptor->GetBlockSize()),
      AbstractEncryptedStream(encryptor) {}

void AsyncEncryptedOutputStream::processWriteBuffer() {
  writeBuffer = encryptor->Encrypt(writeBuffer);
}
