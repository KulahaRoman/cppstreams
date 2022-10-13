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

void FileStream::Read(unsigned char* data, uint64_t size,
                      const std::function<void(uint64_t)>& onSuccess,
                      const std::function<void(const Exception&)>& onFailure) {
  read(data, size, onSuccess, onFailure);
}

uint64_t FileStream::Skip(uint64_t nBytes) { return skip(nBytes); }

void FileStream::Skip(uint64_t size,
                      const std::function<void(uint64_t)>& onSuccess,
                      const std::function<void(const Exception&)>& onFailure) {
  skip(size, onSuccess, onFailure);
}

uint64_t FileStream::Available() { return available(); }

uint64_t FileStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

void FileStream::Write(const unsigned char* data, uint64_t size,
                       const std::function<void(uint64_t)>& onSuccess,
                       const std::function<void(const Exception&)>& onFailure) {
  write(data, size, onSuccess, onFailure);
}

uint64_t FileStream::Flush() { return flush(); }

void FileStream::Flush(const std::function<void(uint64_t)>& onSuccess,
                       const std::function<void(const Exception&)>& onFailure) {
  flush(onSuccess, onFailure);
}
