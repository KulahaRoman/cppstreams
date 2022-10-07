#include "filestream.h"

FileStream::FileStream(const
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

uint64_t FileStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

uint64_t FileStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

uint64_t FileStream::Flush() { return flush(); }

uint64_t FileStream::Available() { return available(); }

uint64_t FileStream::Skip(uint64_t nBytes) { return skip(nBytes); }
