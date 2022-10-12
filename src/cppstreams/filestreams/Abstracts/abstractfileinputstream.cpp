#include "abstractfileinputstream.h"

AbstractFileInputStream::AbstractFileInputStream() : gpos(0) {}

uint64_t AbstractFileInputStream::read(unsigned char* data, uint64_t size) {
  if (!size) {
    return size;
  }

  auto bytesAvailable = available();
  if (bytesAvailable < size) {
    throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
        L"Failed to read bytes (insufficient bytes available)."
#else
        "Failed to read bytes (insufficient bytes available)."
#endif
    );
  }

  std::vector<unsigned char> tempBuffer(static_cast<size_t>(size));

  file.seekg(gpos, std::ios::beg);
  try {
    file.read(reinterpret_cast<char*>(tempBuffer.data()), tempBuffer.size());
  } catch (...) {
    throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
        L"Failed to read bytes (IO error)."
#else
        "Failed to read bytes (IO error)."
#endif
    );
  }

  std::copy(tempBuffer.data(), tempBuffer.data() + tempBuffer.size(), data);

  gpos += size;

  return size;
}

uint64_t AbstractFileInputStream::available() {
  auto currentGPos = gpos;
  file.seekg(0, std::ios::end);
  auto endGPos = file.tellg();
  file.seekg(currentGPos, std::ios::beg);
  return endGPos - currentGPos;
}

uint64_t AbstractFileInputStream::skip(uint64_t size) {
  if (!size) {
    return size;
  }

  auto bytesAvailable = available();
  if (bytesAvailable < size) {
    throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
        L"Failed to skip bytes (insufficient bytes available)."
#else
        "Failed to skip bytes (insufficient bytes available)."
#endif
    );
  }

  try {
    auto newGPos = gpos + std::streampos(size);
    file.seekg(newGPos, std::ios::beg);
    gpos = newGPos;
  } catch (...) {
    throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
        L"Failed to skip bytes (IO error)."
#else
        "Failed to skip bytes (IO error)."
#endif
    );
  }

  return size;
}
