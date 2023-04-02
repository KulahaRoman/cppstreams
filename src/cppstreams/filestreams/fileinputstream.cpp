#include "fileinputstream.h"

FileInputStream::FileInputStream(const std::string& file, bool binary)
    : AbstractFileStream(file, std::ios::in | (binary ? std::ios::binary : std::ios::openmode(0))) {
}

uint64_t FileInputStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

void FileInputStream::Read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  read(data, size, onSuccess, onFailure);
}

uint64_t FileInputStream::Skip(uint64_t nBytes) { return skip(nBytes); }

void FileInputStream::Skip(
    uint64_t size, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  skip(size, onSuccess, onFailure);
}

uint64_t FileInputStream::Available() { return available(); }
