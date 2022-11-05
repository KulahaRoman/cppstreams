#pragma once
#include "../bufferedstreams/bufferedoutputstream.h"
#include "abstracts/abstractencryptedstream.h"

class EncryptedOutputStream : public BufferedOutputStream,
                              virtual protected AbstractEncryptedStream {
 public:
  EncryptedOutputStream(Encryptor& encryptor, OutputStream& stream);

 protected:
  EncryptedOutputStream(OutputStream& stream, uint64_t bufferSize);

 private:
  void processWriteBuffer() override;
};
