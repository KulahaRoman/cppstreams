#include "asyncfileoutputstream.h"

AsyncFileOutputStream::AsyncFileOutputStream(const
#if defined(UNICODE) || defined(_UNICODE)
                                             std::wstring
#else
                                             std::string
#endif
                                                 & file,
                                             bool binary)
    : AbstractFileStream(file,
                         std::ios::out | (binary ? std::ios::binary : 0)) {
}

void AsyncFileOutputStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& callback) {
  write(data, size, callback);
}

void AsyncFileOutputStream::Flush(
    const std::function<void(uint64_t)>& callback) {
  flush(callback);
}
