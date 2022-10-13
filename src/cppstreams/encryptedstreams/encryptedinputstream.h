#pragma once
#include "../bufferedstreams/bufferedinputstream.h"
#include "abstracts/abstractencryptedstream.h"

class EncryptedInputStream : public BufferedInputStream,
                             virtual protected AbstractEncryptedStream {
 public:
  EncryptedInputStream(const std::shared_ptr<Encryptor>& encryptor,
                       const std::shared_ptr<InputStream>& stream);

 protected:
  EncryptedInputStream(const std::shared_ptr<InputStream>& stream,
                       uint64_t bufferSize);

 private:
  void processReadBuffer() override;
};
