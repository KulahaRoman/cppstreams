#pragma once
#include <cpputils/encryptors/encryptor.h>

#include <memory>

class AbstractEncryptedStream {
 protected:
  AbstractEncryptedStream();
  AbstractEncryptedStream(const std::shared_ptr<Encryptor>& encryptor);

  std::shared_ptr<Encryptor> GetEncryptor() const;

 protected:
  std::shared_ptr<Encryptor> encryptor;
};
