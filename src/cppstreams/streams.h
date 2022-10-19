#pragma once
#include <memory>

#include "bufferedstreams/bufferedinputstream.h"
#include "bufferedstreams/bufferedoutputstream.h"
#include "bufferedstreams/bufferedstream.h"
#include "encryptedstreams/encryptedinputstream.h"
#include "encryptedstreams/encryptedoutputstream.h"
#include "encryptedstreams/encryptedstream.h"
#include "filestreams/fileinputstream.h"
#include "filestreams/fileoutputstream.h"
#include "filestreams/filestream.h"
#include "socketstreams/socketinputstream.h"
#include "socketstreams/socketoutputstream.h"
#include "socketstreams/socketstream.h"

class Streams {
 public:
  static std::unique_ptr<InputStream> GetEncryptedInputStream(
      const std::shared_ptr<Encryptor>& encryptor,
      const std::shared_ptr<InputStream>& stream);
  static std::unique_ptr<OutputStream> GetEncryptedOutputStream(
      const std::shared_ptr<Encryptor>& encryptor,
      const std::shared_ptr<OutputStream>& stream);
  static std::unique_ptr<Stream> GetEncryptedStream(
      const std::shared_ptr<Encryptor>& encryptor,
      const std::shared_ptr<Stream>& stream);

  static std::unique_ptr<InputStream> GetBufferedInputStream(
      const std::shared_ptr<InputStream>& stream, uint64_t bufferSize);
  static std::unique_ptr<OutputStream> GetBufferedOutputStream(
      const std::shared_ptr<OutputStream>& stream, uint64_t bufferSize);
  static std::unique_ptr<Stream> GetBufferedStream(
      const std::shared_ptr<Stream>& stream, uint64_t bufferSize);

  static std::unique_ptr<InputStream> GetFileInputStream(
      const std::string& file, bool binaryMode = false);
  static std::unique_ptr<OutputStream> GetFileOutputStream(
      const std::string& file, bool binaryMode = false);
  static std::unique_ptr<Stream> GetFileStream(const std::string& file,
                                               bool binaryMode = false);

  static std::unique_ptr<InputStream> GetSocketInputStream(
      boost::asio::ip::tcp::socket&& socket);
  static std::unique_ptr<OutputStream> GetSocketOutputStream(
      boost::asio::ip::tcp::socket&& socket);
  static std::unique_ptr<Stream> GetSocketStream(
      boost::asio::ip::tcp::socket&& socket);
};
