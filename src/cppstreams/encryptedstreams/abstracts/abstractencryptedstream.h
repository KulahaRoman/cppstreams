#pragma once
#include <cpputils/encryptors/encryptor.h>

#include <memory>

class AbstractEncryptedStream {
 protected:
  AbstractEncryptedStream();
  AbstractEncryptedStream(Encryptor& encryptor);

  Encryptor& GetEncryptor() const;

 protected:
  Encryptor* encryptor;
};
