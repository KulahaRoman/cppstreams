#include "asyncencryptedinputstream.h"

AsyncEncryptedInputStream::AsyncEncryptedInputStream(
    const std::shared_ptr<IAsyncInputStream>& stream, uint64_t bufferSize)
    : AsyncBufferedInputStream(stream, bufferSize) {}

AsyncEncryptedInputStream::AsyncEncryptedInputStream(
    const std::shared_ptr<IEncryptor>& encryptor,
    const std::shared_ptr<IAsyncInputStream>& stream)
    : AsyncBufferedInputStream(stream, encryptor->GetBlockSize()),
      AbstractEncryptedStream(encryptor) {}

void AsyncEncryptedInputStream::processReadBuffer() {
  readBuffer = encryptor->Decrypt(readBuffer);
}
