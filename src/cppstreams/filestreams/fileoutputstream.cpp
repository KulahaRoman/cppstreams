#include "fileoutputstream.h"

FileOutputStream::FileOutputStream(const std::string& file, bool binary)
    : AbstractFileStream(file,
                         std::ios::out | (binary ? std::ios::binary : 0)) {}

uint64_t FileOutputStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

void FileOutputStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  write(data, size, onSuccess, onFailure);
}

uint64_t FileOutputStream::Flush() { return flush(); }

void FileOutputStream::Flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  flush(onSuccess, onFailure);
}
