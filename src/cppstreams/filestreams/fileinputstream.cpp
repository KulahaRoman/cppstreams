#include "fileinputstream.h"

FileInputStream::FileInputStream(const
#if defined(UNICODE) || defined(_UNICODE)
                                 std::wstring
#else
                                 std::string
#endif
                                     & file,
                                 bool binary)
    : AbstractFileStream(file, std::ios::in | (binary ? std::ios::binary : 0)) {
}

uint64_t FileInputStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

uint64_t FileInputStream::Available() { return available(); }

uint64_t FileInputStream::Skip(uint64_t nBytes) { return skip(nBytes); }
