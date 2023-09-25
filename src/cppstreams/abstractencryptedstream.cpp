#include "abstractencryptedstream.h"

namespace CppStreams {
AbstractEncryptedStream::AbstractEncryptedStream() {}

AbstractEncryptedStream::AbstractEncryptedStream(
    const std::shared_ptr<CppUtils::Encryption::Encryptor>& encryptor)
    : encryptor(encryptor) {}

std::shared_ptr<CppUtils::Encryption::Encryptor>
AbstractEncryptedStream::GetEncryptor() const {
  return encryptor;
}
}  // namespace CppStreams
