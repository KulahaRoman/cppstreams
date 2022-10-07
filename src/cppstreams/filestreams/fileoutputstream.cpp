#include "fileoutputstream.h"

FileOutputStream::FileOutputStream(const
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

uint64_t FileOutputStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

uint64_t FileOutputStream::Flush() { return flush(); }
