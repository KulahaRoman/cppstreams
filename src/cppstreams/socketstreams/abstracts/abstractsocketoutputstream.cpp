#include "abstractsocketoutputstream.h"

uint64_t AbstractSocketOutputStream::write(const unsigned char* data,
                                           uint64_t size) {
  if (!size) {
    return size;
  }

  uint64_t bytesWritten = 0ull;
  try {
    bytesWritten = boost::asio::write(
        socket, boost::asio::const_buffer(data, static_cast<size_t>(size)));
  } catch (...) {
    throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
        L"Failed to write bytes (IO error)."
#else
        "Failed to write bytes (IO error)."
#endif
    );
  }
  return bytesWritten;
}

uint64_t AbstractSocketOutputStream::flush() {
  throw RuntimeException(
#if defined(UNICODE) || defined(_UNICODE)
      L"Unsupported stream method (Flush() for non-bufered stream)."
#else
      "Unsupported stream method (Flush() for non-bufered stream)."
#endif
  );
  return 0ull;
}
