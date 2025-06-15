#include "abstractsocketoutputstream.h"

namespace CppStreams {
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
    throw std::runtime_error("Failed to write bytes (IO error).");
  }
  return bytesWritten;
}

uint64_t AbstractSocketOutputStream::flush() {
  throw std::runtime_error(
      "Unsupported stream method (Flush() for non-buffered stream).");
  return 0ull;
}

}  // namespace CppStreams
