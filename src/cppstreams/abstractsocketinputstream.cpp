#include "abstractsocketinputstream.h"

namespace CppStreams {
uint64_t AbstractSocketInputStream::read(unsigned char* data, uint64_t size) {
  if (!size) {
    return size;
  }

  uint64_t bytesRead = 0ull;

  auto tempBuffer =
      std::make_shared<std::vector<unsigned char>>(static_cast<size_t>(size));

  try {
    bytesRead = boost::asio::read(
        socket, boost::asio::buffer(tempBuffer->data(), tempBuffer->size()));
  } catch (...) {
    throw std::runtime_error("Failed to read bytes (IO error).");
  }

  std::copy(tempBuffer->data(), tempBuffer->data() + tempBuffer->size(), data);

  return bytesRead;
}

uint64_t AbstractSocketInputStream::skip(uint64_t nBytes) {
  if (!nBytes) {
    return nBytes;
  }

  uint64_t bytesSkipped = 0ull;

  std::vector<unsigned char> tempBuffer(static_cast<size_t>(nBytes));

  try {
    bytesSkipped = boost::asio::read(
        socket, boost::asio::buffer(tempBuffer.data(), tempBuffer.size()));
  } catch (...) {
    throw std::runtime_error("Failed to skip bytes (IO error).");
  }

  return bytesSkipped;
}

uint64_t AbstractSocketInputStream::available() {
  return static_cast<uint64_t>(socket.available());
}
}  // namespace CppStreams
