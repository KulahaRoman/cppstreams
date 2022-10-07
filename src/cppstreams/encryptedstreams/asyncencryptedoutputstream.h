#pragma once
#include "../bufferedstreams/asyncbufferedoutputstream.h"
#include "abstracts/abstractencryptedstream.h"

class AsyncEncryptedOutputStream : public AsyncBufferedOutputStream,
                                   virtual protected AbstractEncryptedStream {
 public:
  AsyncEncryptedOutputStream(const std::shared_ptr<IEncryptor>& encryptor,
                             const std::shared_ptr<IAsyncOutputStream>& stream);

 protected:
  AsyncEncryptedOutputStream(const std::shared_ptr<IAsyncOutputStream>& stream,
                             uint64_t bufferSize);

 private:
  void processWriteBuffer() override;
};
