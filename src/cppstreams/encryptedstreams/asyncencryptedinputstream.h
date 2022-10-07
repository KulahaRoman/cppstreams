#pragma once
#include "../bufferedstreams/asyncbufferedinputstream.h"
#include "abstracts/abstractencryptedstream.h"

class AsyncEncryptedInputStream : public AsyncBufferedInputStream,
                                  virtual protected AbstractEncryptedStream {
 public:
  AsyncEncryptedInputStream(const std::shared_ptr<IEncryptor>& encryptor,
                            const std::shared_ptr<IAsyncInputStream>& stream);

 protected:
  AsyncEncryptedInputStream(const std::shared_ptr<IAsyncInputStream>& stream,
                            uint64_t bufferSize);

 private:
  void processReadBuffer() override;
};
