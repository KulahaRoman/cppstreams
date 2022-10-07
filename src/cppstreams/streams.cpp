#include "Streams.h"

std::unique_ptr<IAsyncInputStream> Streams::GetAsyncEncryptedInputStream(
    const std::shared_ptr<IEncryptor>& encryptor,
    const std::shared_ptr<IAsyncInputStream>& stream) {
  return std::make_unique<AsyncEncryptedInputStream>(encryptor, stream);
}

std::unique_ptr<IAsyncOutputStream> Streams::GetAsyncEncryptedOutputStream(
    const std::shared_ptr<IEncryptor>& encryptor,
    const std::shared_ptr<IAsyncOutputStream>& stream) {
  return std::make_unique<AsyncEncryptedOutputStream>(encryptor, stream);
}

std::unique_ptr<IAsyncStream> Streams::GetAsyncEncryptedStream(
    const std::shared_ptr<IEncryptor>& encryptor,
    const std::shared_ptr<IAsyncStream>& stream) {
  return std::make_unique<AsyncEncryptedStream>(encryptor, stream);
}

std::unique_ptr<IInputStream> Streams::GetEncryptedInputStream(
    const std::shared_ptr<IEncryptor>& encryptor,
    const std::shared_ptr<IInputStream>& stream) {
  return std::make_unique<EncryptedInputStream>(encryptor, stream);
}

std::unique_ptr<IOutputStream> Streams::GetEncryptedOutputStream(
    const std::shared_ptr<IEncryptor>& encryptor,
    const std::shared_ptr<IOutputStream>& stream) {
  return std::make_unique<EncryptedOutputStream>(encryptor, stream);
}

std::unique_ptr<IStream> Streams::GetEncryptedStream(
    const std::shared_ptr<IEncryptor>& encryptor,
    const std::shared_ptr<IStream>& stream) {
  return std::make_unique<EncryptedStream>(encryptor, stream);
}

std::unique_ptr<IAsyncInputStream> Streams::GetAsyncBufferedInputStream(
    const std::shared_ptr<IAsyncInputStream>& stream, uint64_t bufferSize) {
  return std::make_unique<AsyncBufferedInputStream>(stream, bufferSize);
}

std::unique_ptr<IAsyncOutputStream> Streams::GetAsyncBufferedOutputStream(
    const std::shared_ptr<IAsyncOutputStream>& stream, uint64_t bufferSize) {
  return std::make_unique<AsyncBufferedOutputStream>(stream, bufferSize);
}

std::unique_ptr<IAsyncStream> Streams::GetAsyncBufferedStream(
    const std::shared_ptr<IAsyncStream>& stream, uint64_t bufferSize) {
  return std::make_unique<AsyncBufferedStream>(stream, bufferSize);
}

std::unique_ptr<IInputStream> Streams::GetBufferedInputStream(
    const std::shared_ptr<IInputStream>& stream, uint64_t bufferSize) {
  return std::make_unique<BufferedInputStream>(stream, bufferSize);
}

std::unique_ptr<IOutputStream> Streams::GetBufferedOutputStream(
    const std::shared_ptr<IOutputStream>& stream, uint64_t bufferSize) {
  return std::make_unique<BufferedOutputStream>(stream, bufferSize);
}

std::unique_ptr<IStream> Streams::GetBufferedStream(
    const std::shared_ptr<IStream>& stream, uint64_t bufferSize) {
  return std::make_unique<BufferedStream>(stream, bufferSize);
}

#if defined(UNICODE) || defined(_UNICODE)
std::unique_ptr<IAsyncInputStream> Streams::GetAsyncFileInputStream(
    const std::wstring& file, bool binaryMode) {
  return std::make_unique<AsyncFileInputStream>(file, binaryMode);
}

std::unique_ptr<IAsyncOutputStream> Streams::GetAsyncFileOutputStream(
    const std::wstring& file, bool binaryMode) {
  return std::make_unique<AsyncFileOutputStream>(file, binaryMode);
}

std::unique_ptr<IAsyncStream> Streams::GetAsyncFileStream(
    const std::wstring& file, bool binaryMode) {
  return std::make_unique<AsyncFileStream>(file, binaryMode);
}

std::unique_ptr<IInputStream> Streams::GetFileInputStream(
    const std::wstring& file, bool binaryMode) {
  return std::make_unique<FileInputStream>(file, binaryMode);
}

std::unique_ptr<IOutputStream> Streams::GetFileOutputStream(
    const std::wstring& file, bool binaryMode) {
  return std::make_unique<FileOutputStream>(file, binaryMode);
}

std::unique_ptr<IStream> Streams::GetFileStream(const std::wstring& file,
                                                bool binaryMode) {
  return std::make_unique<FileStream>(file, binaryMode);
}
#else
std::unique_ptr<IAsyncInputStream> Streams::GetAsyncFileInputStream(
    const std::string& file, bool binaryMode) {
  return std::make_unique<AsyncFileInputStream>(file, binaryMode);
}

std::unique_ptr<IAsyncOutputStream> Streams::GetAsyncFileOutputStream(
    const std::string& file, bool binaryMode) {
  return std::make_unique<AsyncFileOutputStream>(file, binaryMode);
}

std::unique_ptr<IAsyncStream> Streams::GetAsyncFileStream(
    const std::string& file, bool binaryMode) {
  return std::make_unique<AsyncFileStream>(file, binaryMode);
}

std::unique_ptr<IInputStream> Streams::GetFileInputStream(
    const std::string& file, bool binaryMode) {
  return std::make_unique<FileInputStream>(file, binaryMode);
}

std::unique_ptr<IOutputStream> Streams::GetFileOutputStream(
    const std::string& file, bool binaryMode) {
  return std::make_unique<FileOutputStream>(file, binaryMode);
}

std::unique_ptr<IStream> Streams::GetFileStream(const std::string& file,
                                                bool binaryMode) {
  return std::make_unique<FileStream>(file, binaryMode);
}
#endif

std::unique_ptr<IAsyncInputStream> Streams::GetAsyncSocketInputStream(
    boost::asio::ip::tcp::socket&& socket) {
  return std::make_unique<AsyncSocketInputStream>(std::move(socket));
}

std::unique_ptr<IAsyncOutputStream> Streams::GetAsyncSocketOutputStream(
    boost::asio::ip::tcp::socket&& socket) {
  return std::make_unique<AsyncSocketOutputStream>(std::move(socket));
}

std::unique_ptr<IAsyncStream> Streams::GetAsyncSocketStream(
    boost::asio::ip::tcp::socket&& socket) {
  return std::make_unique<AsyncSocketStream>(std::move(socket));
}

std::unique_ptr<IInputStream> Streams::GetSocketInputStream(
    boost::asio::ip::tcp::socket&& socket) {
  return std::make_unique<SocketInputStream>(std::move(socket));
}

std::unique_ptr<IOutputStream> Streams::GetSocketOutputStream(
    boost::asio::ip::tcp::socket&& socket) {
  return std::make_unique<SocketOutputStream>(std::move(socket));
}

std::unique_ptr<IStream> Streams::GetSocketStream(
    boost::asio::ip::tcp::socket&& socket) {
  return std::make_unique<SocketStream>(std::move(socket));
}
