#include "abstractfilestream.h"

AbstractFileStream::AbstractFileStream() {}

AbstractFileStream::AbstractFileStream(const
#if defined(UNICODE) || defined(_UNICODE)
                                       std::wstring
#else
                                       std::string
#endif
                                           & file,
                                       const std::ios::openmode& openMode) {
  this->file.exceptions(std::ios::failbit | std::ios::badbit |
                        std::ios::eofbit);
  try {
    this->file.open(file, openMode);
  } catch (...) {
    throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
        L"Failed to open file stream: cannot open file."
#else
        "Failed to open file stream: cannot open file."
#endif
    );
  }
}

AbstractFileStream::~AbstractFileStream() {
  if (file.is_open()) {
    file.close();
  }
}
