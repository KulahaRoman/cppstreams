#pragma once
#include "abstractencryptedstream.h"
#include "encryptedinputstream.h"
#include "encryptedoutputstream.h"
#include "stream.h"

namespace CppStreams {
class EncryptedStream : public Stream,
                        private EncryptedInputStream,
                        private EncryptedOutputStream {
 public:
  EncryptedStream(
      const std::shared_ptr<CppUtils::Encryption::Encryptor>& encryptor,
      const std::shared_ptr<Stream>& stream);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  uint64_t Skip(uint64_t size) override;
  uint64_t Available() override;
  uint64_t Write(const unsigned char* data, uint64_t size) override;
  uint64_t Flush() override;
};
}  // namespace CppStreams
