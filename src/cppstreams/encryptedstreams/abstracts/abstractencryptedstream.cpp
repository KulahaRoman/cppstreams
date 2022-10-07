#include "abstractencryptedstream.h"

AbstractEncryptedStream::AbstractEncryptedStream() {}

AbstractEncryptedStream::AbstractEncryptedStream(
    const std::shared_ptr<IEncryptor>& encryptor)
    : encryptor(encryptor) {}

std::shared_ptr<IEncryptor> AbstractEncryptedStream::GetEncryptor() const {
  return encryptor;
}
