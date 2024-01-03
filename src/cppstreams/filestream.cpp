#include "filestream.h"

namespace CppStreams {
FileStream::FileStream(const std::string& file, bool binary)
    : AbstractFileStream(
          file, std::ios::in | std::ios::out |
                    (binary ? std::ios::binary : std::ios::openmode(0))) {}

uint64_t FileStream::Read(unsigned char* data, uint64_t size) {
  return AbstractFileInputStream::Read(data, size);
}

void FileStream::Read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  AbstractFileInputStream::Read(data, size, onSuccess, onFailure);
}

uint64_t FileStream::Skip(uint64_t nBytes) {
  return AbstractFileInputStream::Skip(nBytes);
}

void FileStream::Skip(
    uint64_t size, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  AbstractFileInputStream::Skip(size, onSuccess, onFailure);
}

uint64_t FileStream::Available() {
  return AbstractFileInputStream::Available();
}

uint64_t FileStream::Write(const unsigned char* data, uint64_t size) {
  return AbstractFileOutputStream::Write(data, size);
}

void FileStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  AbstractFileOutputStream::Write(data, size, onSuccess, onFailure);
}

uint64_t FileStream::Flush() { return AbstractFileOutputStream::Flush(); }

void FileStream::Flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  AbstractFileOutputStream::Flush(onSuccess, onFailure);
}
}  // namespace CppStreams
