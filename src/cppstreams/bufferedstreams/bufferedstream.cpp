#include "bufferedstream.h"

BufferedStream::BufferedStream(Stream& stream, uint64_t bufferSize)
    : AbstractBufferedInputStream(stream, bufferSize),
      AbstractBufferedOutputStream(stream, bufferSize) {}

uint64_t BufferedStream::Read(unsigned char* data, uint64_t size) {
  return read(data, size);
}

void BufferedStream::Read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  read(data, size, onSuccess, onFailure);
}

uint64_t BufferedStream::Skip(uint64_t nBytes) { return skip(nBytes); }

void BufferedStream::Skip(
    uint64_t size, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  skip(size, onSuccess, onFailure);
}

uint64_t BufferedStream::Available() { return available(); }

uint64_t BufferedStream::Write(const unsigned char* data, uint64_t size) {
  return write(data, size);
}

void BufferedStream::Write(
    const unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  write(data, size, onSuccess, onFailure);
}

uint64_t BufferedStream::Flush() { return flush(); }

void BufferedStream::Flush(
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const Exception&)>& onFailure) {
  flush(onSuccess, onFailure);
}
