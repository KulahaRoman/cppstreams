#pragma once
#include <boost/asio.hpp>

class AbstractSocketStream {
 protected:
  AbstractSocketStream();
  AbstractSocketStream(boost::asio::ip::tcp::socket&& socket);
  ~AbstractSocketStream();

 protected:
  boost::asio::ip::tcp::socket socket;
};
