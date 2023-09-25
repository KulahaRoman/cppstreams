#include "encryptedoutputstream.h"

namespace CppStreams {
EncryptedOutputStream::EncryptedOutputStream(
    const std::shared_ptr<OutputStream>& stream, uint64_t bufferSize)
    : BufferedOutputStream(stream, bufferSize) {}

EncryptedOutputStream::EncryptedOutputStream(
    const std::shared_ptr<Encryptor>& encryptor,
    const std::shared_ptr<OutputStream>& stream)
    : BufferedOutputStream(stream, encryptor->GetBlockSize()),
      AbstractEncryptedStream(encryptor) {}

void EncryptedOutputStream::processWriteBuffer() {
  writeBuffer = encryptor->Encrypt(writeBuffer);
}
}  // namespace CppStreams
