#include "abstractfileinputstream.h"

namespace CppStreams {
AbstractFileInputStream::AbstractFileInputStream() : gpos(0) {}

uint64_t AbstractFileInputStream::read(unsigned char* data, uint64_t size) {
  if (!size) {
    return size;
  }

  auto bytesAvailable = available();
  if (bytesAvailable < size) {
    throw std::runtime_error(
        "Failed to read bytes (insufficient bytes available).");
  }

  std::vector<unsigned char> tempBuffer(static_cast<size_t>(size));

  file.seekg(gpos, std::ios::beg);
  try {
    file.read(reinterpret_cast<char*>(tempBuffer.data()), tempBuffer.size());
  } catch (...) {
    throw std::runtime_error("Failed to read bytes (IO error).");
  }

  std::copy(tempBuffer.data(), tempBuffer.data() + tempBuffer.size(), data);

  gpos += size;

  return size;
}

void AbstractFileInputStream::read(
    unsigned char* data, uint64_t size,
    const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  CppUtils::ThreadPool::AcceptTask(
      [this, data, size, onSuccess, onFailure,
       self = std::shared_ptr<AbstractFileStream>(this)] {
        try {
          auto result = AbstractFileInputStream::read(data, size);
          if (onSuccess) {
            onSuccess(result);
          }
        } catch (const std::exception& ex) {
          if (onFailure) {
            onFailure(ex);
          }
        }
      });
}

uint64_t AbstractFileInputStream::skip(uint64_t size) {
  if (!size) {
    return size;
  }

  auto bytesAvailable = available();
  if (bytesAvailable < size) {
    throw std::runtime_error(
        "Failed to skip bytes (insufficient bytes available).");
  }

  try {
    auto newGPos = gpos + std::streampos(size);
    file.seekg(newGPos, std::ios::beg);
    gpos = newGPos;
  } catch (...) {
    throw std::runtime_error("Failed to skip bytes (IO error).");
  }

  return size;
}

void AbstractFileInputStream::skip(
    uint64_t size, const std::function<void(uint64_t)>& onSuccess,
    const std::function<void(const std::exception&)>& onFailure) {
  CppUtils::ThreadPool::AcceptTask(
      [this, size, onSuccess, onFailure,
       self = std::shared_ptr<AbstractFileStream>(this)] {
        try {
          auto result = AbstractFileInputStream::skip(size);
          if (onSuccess) {
            onSuccess(result);
          }
        } catch (const std::exception& ex) {
          if (onFailure) {
            onFailure(ex);
          }
        }
      });
}

uint64_t AbstractFileInputStream::available() {
  auto currentGPos = gpos;
  file.seekg(0, std::ios::end);
  auto endGPos = file.tellg();
  file.seekg(currentGPos, std::ios::beg);
  return endGPos - currentGPos;
}
}  // namespace CppStreams
