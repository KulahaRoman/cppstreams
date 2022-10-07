#pragma once
#include <cpputils/exceptions/exceptions.h>

#include <boost/asio.hpp>

class AbstractSocketStream {
 protected:
  AbstractSocketStream();
  AbstractSocketStream(boost::asio::ip::tcp::socket&& socket);
  ~AbstractSocketStream();

 protected:
  boost::asio::ip::tcp::socket socket;
};
