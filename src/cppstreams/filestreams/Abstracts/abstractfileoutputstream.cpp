#include "abstractfileoutputstream.h"

AbstractFileOutputStream::AbstractFileOutputStream() : ppos(0) {}

uint64_t AbstractFileOutputStream::write(const unsigned char* data,
                                         uint64_t size) {
  if (!size) {
    return size;
  }

  file.seekp(ppos, std::ios::beg);

  try {
    file.write(reinterpret_cast<const char*>(data), size);
  } catch (...) {
    throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
        L"Failed to write bytes (IO error)."
#else
        "Failed to write bytes (IO error)."
#endif
    );
  }

  ppos += size;

  return size;
}

uint64_t AbstractFileOutputStream::flush() {
  throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
      L"Unsupported stream method (Flush() for non-bufered stream)."
#else
      "Unsupported stream method (Flush() for non-bufered stream)."
#endif
  );
  return 0ull;
}
