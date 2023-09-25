#pragma once
#include "abstractencryptedstream.h"
#include "bufferedinputstream.h"

namespace CppStreams {
class EncryptedInputStream : public BufferedInputStream,
                             virtual protected AbstractEncryptedStream {
 public:
  EncryptedInputStream(
      const std::shared_ptr<CppUtils::Encryption::Encryptor>& encryptor,
      const std::shared_ptr<InputStream>& stream);

 protected:
  EncryptedInputStream(const std::shared_ptr<InputStream>& stream,
                       uint64_t bufferSize);

 private:
  void processReadBuffer() override;
};
}  // namespace CppStreams
