#pragma once
#include <cpputils/encryptors/iencryptor.h>

#include <memory>

class AbstractEncryptedStream {
 protected:
  AbstractEncryptedStream();
  AbstractEncryptedStream(const std::shared_ptr<IEncryptor>& encryptor);

  std::shared_ptr<IEncryptor> GetEncryptor() const;

 protected:
  std::shared_ptr<IEncryptor> encryptor;
};
