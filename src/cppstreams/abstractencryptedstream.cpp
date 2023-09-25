#include "abstractencryptedstream.h"

namespace CppStreams {
AbstractEncryptedStream::AbstractEncryptedStream() {}

AbstractEncryptedStream::AbstractEncryptedStream(
    const std::shared_ptr<Encryptor>& encryptor)
    : encryptor(encryptor) {}

std::shared_ptr<Encryptor> AbstractEncryptedStream::GetEncryptor() const {
  return encryptor;
}
}  // namespace CppStreams
