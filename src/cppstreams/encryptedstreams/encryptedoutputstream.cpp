#include "encryptedoutputstream.h"

EncryptedOutputStream::EncryptedOutputStream(OutputStream& stream,
                                             uint64_t bufferSize)
    : BufferedOutputStream(stream, bufferSize) {}

EncryptedOutputStream::EncryptedOutputStream(Encryptor& encryptor,
                                             OutputStream& stream)
    : BufferedOutputStream(stream, encryptor.GetBlockSize()),
      AbstractEncryptedStream(encryptor) {}

void EncryptedOutputStream::processWriteBuffer() {
  writeBuffer = encryptor->Encrypt(writeBuffer);
}
