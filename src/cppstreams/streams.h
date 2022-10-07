#pragma once
#include <memory>

#include "bufferedstreams/asyncbufferedinputstream.h"
#include "bufferedstreams/asyncbufferedoutputstream.h"
#include "bufferedstreams/asyncbufferedstream.h"
#include "bufferedstreams/bufferedinputstream.h"
#include "bufferedstreams/bufferedoutputstream.h"
#include "bufferedstreams/bufferedstream.h"
#include "encryptedstreams/asyncencryptedinputstream.h"
#include "encryptedstreams/asyncencryptedoutputstream.h"
#include "encryptedstreams/asyncencryptedstream.h"
#include "encryptedstreams/encryptedinputstream.h"
#include "encryptedstreams/encryptedoutputstream.h"
#include "encryptedstreams/encryptedstream.h"
#include "filestreams/asyncfileinputstream.h"
#include "filestreams/asyncfileoutputstream.h"
#include "filestreams/asyncfilestream.h"
#include "filestreams/fileinputstream.h"
#include "filestreams/fileoutputstream.h"
#include "filestreams/filestream.h"
#include "socketstreams/asyncsocketinputstream.h"
#include "socketstreams/asyncsocketoutputstream.h"
#include "socketstreams/asyncsocketstream.h"
#include "socketstreams/socketinputstream.h"
#include "socketstreams/socketoutputstream.h"
#include "socketstreams/socketstream.h"

class Streams {
 public:
  static std::unique_ptr<IAsyncInputStream> GetAsyncEncryptedInputStream(
      const std::shared_ptr<IEncryptor>& encryptor,
      const std::shared_ptr<IAsyncInputStream>& stream);
  static std::unique_ptr<IAsyncOutputStream> GetAsyncEncryptedOutputStream(
      const std::shared_ptr<IEncryptor>& encryptor,
      const std::shared_ptr<IAsyncOutputStream>& stream);
  static std::unique_ptr<IAsyncStream> GetAsyncEncryptedStream(
      const std::shared_ptr<IEncryptor>& encryptor,
      const std::shared_ptr<IAsyncStream>& stream);
  static std::unique_ptr<IInputStream> GetEncryptedInputStream(
      const std::shared_ptr<IEncryptor>& encryptor,
      const std::shared_ptr<IInputStream>& stream);
  static std::unique_ptr<IOutputStream> GetEncryptedOutputStream(
      const std::shared_ptr<IEncryptor>& encryptor,
      const std::shared_ptr<IOutputStream>& stream);
  static std::unique_ptr<IStream> GetEncryptedStream(
      const std::shared_ptr<IEncryptor>& encryptor,
      const std::shared_ptr<IStream>& stream);

  static std::unique_ptr<IAsyncInputStream> GetAsyncBufferedInputStream(
      const std::shared_ptr<IAsyncInputStream>& stream, uint64_t bufferSize);
  static std::unique_ptr<IAsyncOutputStream> GetAsyncBufferedOutputStream(
      const std::shared_ptr<IAsyncOutputStream>& stream, uint64_t bufferSize);
  static std::unique_ptr<IAsyncStream> GetAsyncBufferedStream(
      const std::shared_ptr<IAsyncStream>& stream, uint64_t bufferSize);
  static std::unique_ptr<IInputStream> GetBufferedInputStream(
      const std::shared_ptr<IInputStream>& stream, uint64_t bufferSize);
  static std::unique_ptr<IOutputStream> GetBufferedOutputStream(
      const std::shared_ptr<IOutputStream>& stream, uint64_t bufferSize);
  static std::unique_ptr<IStream> GetBufferedStream(
      const std::shared_ptr<IStream>& stream, uint64_t bufferSize);

#if defined(UNICODE) || defined(_UNICODE)
  static std::unique_ptr<IAsyncInputStream> GetAsyncFileInputStream(
      const std::wstring& file, bool binaryMode = false);
  static std::unique_ptr<IAsyncOutputStream> GetAsyncFileOutputStream(
      const std::wstring& file, bool binaryMode = false);
  static std::unique_ptr<IAsyncStream> GetAsyncFileStream(
      const std::wstring& file, bool binaryMode = false);
  static std::unique_ptr<IInputStream> GetFileInputStream(
      const std::wstring& file, bool binaryMode = false);
  static std::unique_ptr<IOutputStream> GetFileOutputStream(
      const std::wstring& file, bool binaryMode = false);
  static std::unique_ptr<IStream> GetFileStream(const std::wstring& file,
                                                bool binaryMode = false);
#else
  static std::unique_ptr<IAsyncInputStream> GetAsyncFileInputStream(
      const std::string& file, bool binaryMode = false);
  static std::unique_ptr<IAsyncOutputStream> GetAsyncFileOutputStream(
      const std::string& file, bool binaryMode = false);
  static std::unique_ptr<IAsyncStream> GetAsyncFileStream(
      const std::string& file, bool binaryMode = false);
  static std::unique_ptr<IInputStream> GetFileInputStream(
      const std::string& file, bool binaryMode = false);
  static std::unique_ptr<IOutputStream> GetFileOutputStream(
      const std::string& file, bool binaryMode = false);
  static std::unique_ptr<IStream> GetFileStream(const std::string& file,
                                                bool binaryMode = false);
#endif

  static std::unique_ptr<IAsyncInputStream> GetAsyncSocketInputStream(
      boost::asio::ip::tcp::socket&& socket);
  static std::unique_ptr<IAsyncOutputStream> GetAsyncSocketOutputStream(
      boost::asio::ip::tcp::socket&& socket);
  static std::unique_ptr<IAsyncStream> GetAsyncSocketStream(
      boost::asio::ip::tcp::socket&& socket);
  static std::unique_ptr<IInputStream> GetSocketInputStream(
      boost::asio::ip::tcp::socket&& socket);
  static std::unique_ptr<IOutputStream> GetSocketOutputStream(
      boost::asio::ip::tcp::socket&& socket);
  static std::unique_ptr<IStream> GetSocketStream(
      boost::asio::ip::tcp::socket&& socket);
};
