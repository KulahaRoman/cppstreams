#pragma once
#include "../bufferedstreams/bufferedoutputstream.h"
#include "abstracts/abstractencryptedstream.h"

class EncryptedOutputStream : public BufferedOutputStream,
                              virtual protected AbstractEncryptedStream {
 public:
  EncryptedOutputStream(const std::shared_ptr<IEncryptor>& encryptor,
                        const std::shared_ptr<IOutputStream>& stream);

 protected:
  EncryptedOutputStream(const std::shared_ptr<IOutputStream>& stream,
                        uint64_t bufferSize);

 private:
  void processWriteBuffer() override;
};
