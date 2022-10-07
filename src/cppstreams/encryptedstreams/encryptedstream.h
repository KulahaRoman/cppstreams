#pragma once
#include "../istream.h"
#include "abstracts/abstractencryptedstream.h"
#include "encryptedinputstream.h"
#include "encryptedoutputstream.h"

class EncryptedStream : public IStream,
                        private EncryptedInputStream,
                        private EncryptedOutputStream {
 public:
  EncryptedStream(const std::shared_ptr<IEncryptor>& encryptor,
                  const std::shared_ptr<IStream>& stream);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  uint64_t Available() override;
  uint64_t Skip(uint64_t nBytes) override;

  uint64_t Write(const unsigned char* data, uint64_t size) override;
  uint64_t Flush() override;
};
