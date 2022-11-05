#include "abstractencryptedstream.h"

AbstractEncryptedStream::AbstractEncryptedStream() : encryptor(nullptr) {}

AbstractEncryptedStream::AbstractEncryptedStream(Encryptor& encryptor)
    : encryptor(&encryptor) {}

Encryptor& AbstractEncryptedStream::GetEncryptor() const { return *encryptor; }
