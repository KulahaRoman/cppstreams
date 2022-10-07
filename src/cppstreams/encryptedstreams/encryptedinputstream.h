#pragma once
#include "../bufferedstreams/bufferedinputstream.h"
#include "abstracts/abstractencryptedstream.h"

class EncryptedInputStream : public BufferedInputStream,
                             virtual protected AbstractEncryptedStream {
 public:
  EncryptedInputStream(const std::shared_ptr<IEncryptor>& encryptor,
                       const std::shared_ptr<IInputStream>& stream);

 protected:
  EncryptedInputStream(const std::shared_ptr<IInputStream>& stream,
                       uint64_t bufferSize);

 private:
  void processReadBuffer() override;
};
