#pragma once
#include <boost/asio.hpp>

namespace CppStreams {
class AbstractSocketStream
    : public std::enable_shared_from_this<AbstractSocketStream> {
 protected:
  AbstractSocketStream();
  AbstractSocketStream(boost::asio::ip::tcp::socket&& socket);
  ~AbstractSocketStream();

 protected:
  boost::asio::ip::tcp::socket socket;
};
}  // namespace CppStreams
