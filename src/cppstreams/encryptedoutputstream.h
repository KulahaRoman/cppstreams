#pragma once
#include "abstractencryptedstream.h"
#include "bufferedoutputstream.h"

namespace CppStreams {
class EncryptedOutputStream : public BufferedOutputStream,
                              virtual protected AbstractEncryptedStream {
 public:
  EncryptedOutputStream(
      const std::shared_ptr<CppUtils::Encryption::Encryptor>& encryptor,
      const std::shared_ptr<OutputStream>& stream);

 protected:
  EncryptedOutputStream(const std::shared_ptr<OutputStream>& stream,
                        uint64_t bufferSize);

 private:
  void processWriteBuffer() override;
};
}  // namespace CppStreams
