#pragma once
#include "../bufferedstreams/bufferedoutputstream.h"
#include "abstracts/abstractencryptedstream.h"

namespace CppStreams {
class EncryptedOutputStream : public BufferedOutputStream,
                              virtual protected AbstractEncryptedStream {
 public:
  EncryptedOutputStream(const std::shared_ptr<Encryptor>& encryptor,
                        const std::shared_ptr<OutputStream>& stream);

 protected:
  EncryptedOutputStream(const std::shared_ptr<OutputStream>& stream,
                        uint64_t bufferSize);

 private:
  void processWriteBuffer() override;
};
}  // namespace CppStreams
