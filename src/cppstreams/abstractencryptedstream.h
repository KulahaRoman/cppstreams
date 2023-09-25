#pragma once
#include <cpputils/encryptor.h>

#include <memory>

namespace CppStreams {
class AbstractEncryptedStream {
 protected:
  AbstractEncryptedStream();
  AbstractEncryptedStream(
      const std::shared_ptr<CppUtils::Encryption::Encryptor>& encryptor);

  std::shared_ptr<CppUtils::Encryption::Encryptor> GetEncryptor() const;

 protected:
  std::shared_ptr<CppUtils::Encryption::Encryptor> encryptor;
};
}  // namespace CppStreams
