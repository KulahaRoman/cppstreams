#include "encryptedinputstream.h"

namespace CppStreams {
EncryptedInputStream::EncryptedInputStream(
    const std::shared_ptr<InputStream>& stream, uint64_t bufferSize)
    : BufferedInputStream(stream, bufferSize) {}

EncryptedInputStream::EncryptedInputStream(
    const std::shared_ptr<CppUtils::Encryption::Encryptor>& encryptor,
    const std::shared_ptr<InputStream>& stream)
    : BufferedInputStream(stream, encryptor->GetBlockSize()),
      AbstractEncryptedStream(encryptor) {}

void EncryptedInputStream::processReadBuffer() {
  readBuffer = encryptor->Decrypt(readBuffer);
}
}  // namespace CppStreams
