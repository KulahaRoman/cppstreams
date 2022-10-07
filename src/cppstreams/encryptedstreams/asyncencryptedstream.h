#pragma once
#include "../iasyncstream.h"
#include "asyncencryptedinputstream.h"
#include "asyncencryptedoutputstream.h"

class AsyncEncryptedStream : public IAsyncStream,
                             private AsyncEncryptedInputStream,
                             private AsyncEncryptedOutputStream {
 public:
  AsyncEncryptedStream(const std::shared_ptr<IEncryptor>& encryptor,
                       const std::shared_ptr<IAsyncStream>& stream);

  void Read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& callback) override;
  uint64_t Available() override;
  void Skip(uint64_t nBytes,
            const std::function<void(uint64_t)>& callback) override;

  void Write(const unsigned char* data, uint64_t size,
             const std::function<void(uint64_t)>& callback) override;
  void Flush(const std::function<void(uint64_t)>& callback) override;
};
