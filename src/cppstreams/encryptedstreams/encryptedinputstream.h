#pragma once
#include "../bufferedstreams/bufferedinputstream.h"
#include "abstracts/abstractencryptedstream.h"

class EncryptedInputStream : public BufferedInputStream,
                             virtual protected AbstractEncryptedStream {
 public:
  EncryptedInputStream(Encryptor& encryptor, InputStream& stream);

 protected:
  EncryptedInputStream(InputStream& stream, uint64_t bufferSize);

 private:
  void processReadBuffer() override;
};
