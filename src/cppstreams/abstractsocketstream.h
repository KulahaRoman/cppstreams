#pragma once
#include <boost/asio.hpp>

namespace CppStreams {
class AbstractSocketStream {
 protected:
  AbstractSocketStream();
  AbstractSocketStream(boost::asio::ip::tcp::socket&& socket);
  ~AbstractSocketStream();

 protected:
  boost::asio::ip::tcp::socket socket;
};
}  // namespace CppStreams
