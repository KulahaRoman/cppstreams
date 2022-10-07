#include "asyncfilestream.h"

AsyncFileStream::AsyncFileStream(const
#if defined(UNICODE) || defined(_UNICODE)
                                 std::wstring
#else
                                 std::string
#endif
                                     & file,
                                 bool binary)
    : AbstractFileStream(file, std::ios::in | std::ios::out |
                                   (binary ? std::ios::binary : 0)) {
}

void AsyncFileStream::Read(unsigned char* data, uint64_t size,
                           const std::function<void(uint64_t)>& callback) {
  read(data, size, callback);
}

void AsyncFileStream::Write(const unsigned char* data, uint64_t size,
                            const std::function<void(uint64_t)>& callback) {
  write(data, size, callback);
}

void AsyncFileStream::Flush(const std::function<void(uint64_t)>& callback) {
  flush(callback);
}

uint64_t AsyncFileStream::Available() { return available(); }

void AsyncFileStream::Skip(uint64_t nBytes,
                           const std::function<void(uint64_t)>& callback) {
  skip(nBytes, callback);
}
