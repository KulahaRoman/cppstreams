#include "asyncfileinputstream.h"

AsyncFileInputStream::AsyncFileInputStream(const
#if defined(UNICODE) || defined(_UNICODE)
                                           std::wstring
#else
                                           std::string
#endif
                                               & file,
                                           bool binary)
    : AbstractFileStream(file, std::ios::in | (binary ? std::ios::binary : 0)) {
}

void AsyncFileInputStream::Read(unsigned char* data, uint64_t size,
                                const std::function<void(uint64_t)>& callback) {
  read(data, size, callback);
}

uint64_t AsyncFileInputStream::Available() { return available(); }

void AsyncFileInputStream::Skip(uint64_t nBytes,
                                const std::function<void(uint64_t)>& callback) {
  skip(nBytes, callback);
}
