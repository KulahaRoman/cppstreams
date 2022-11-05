#include "encryptedinputstream.h"

EncryptedInputStream::EncryptedInputStream(InputStream& stream,
                                           uint64_t bufferSize)
    : BufferedInputStream(stream, bufferSize) {}

EncryptedInputStream::EncryptedInputStream(Encryptor& encryptor,
                                           InputStream& stream)
    : BufferedInputStream(stream, encryptor.GetBlockSize()),
      AbstractEncryptedStream(encryptor) {}

void EncryptedInputStream::processReadBuffer() {
  readBuffer = encryptor->Decrypt(readBuffer);
}
