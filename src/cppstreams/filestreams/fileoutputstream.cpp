#include "fileoutputstream.h"

FileOutputStream::FileOutputStream(const std::string& file, bool binary)
    : AbstractFileStream(file,
                         std::ios::out | (binary ? std::ios::binary : std::ios::openmode(0))) {}

uint64_t FileOutputStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

void FileOutputStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  write(data, size, onSuccess, onFailure);
}

uint64_t FileOutputStream::Flush() { return flush(); }

void FileOutputStream::Flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  flush(onSuccess, onFailure);
}
