#pragma once
#include "../inputstream.h"
#include "abstracts/abstractsocketinputstream.h"

namespace CppStreams {
class SocketInputStream : private AbstractSocketInputStream,
                          public InputStream {
 public:
  SocketInputStream(boost::asio::ip::tcp::socket&& socket);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  void Read(unsigned char* data, uint64_t size,
            const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const std::exception&)>& onFailure =
                nullptr) override;

  uint64_t Skip(uint64_t size) override;
  void Skip(uint64_t size, const std::function<void(uint64_t)>& onSuccess,
            const std::function<void(const std::exception&)>& onFailure =
                nullptr) override;

  uint64_t Available() override;
};
}  // namespace CppStreams
