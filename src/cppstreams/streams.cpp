#include "Streams.h"

std::unique_ptr<InputStream> Streams::GetEncryptedInputStream(
    const std::shared_ptr<Encryptor>& encryptor,
    const std::shared_ptr<InputStream>& stream) {
  return std::make_unique<EncryptedInputStream>(encryptor, stream);
}

std::unique_ptr<OutputStream> Streams::GetEncryptedOutputStream(
    const std::shared_ptr<Encryptor>& encryptor,
    const std::shared_ptr<OutputStream>& stream) {
  return std::make_unique<EncryptedOutputStream>(encryptor, stream);
}

std::unique_ptr<Stream> Streams::GetEncryptedStream(
    const std::shared_ptr<Encryptor>& encryptor,
    const std::shared_ptr<Stream>& stream) {
  return std::make_unique<EncryptedStream>(encryptor, stream);
}

std::unique_ptr<InputStream> Streams::GetBufferedInputStream(
    const std::shared_ptr<InputStream>& stream, uint64_t bufferSize) {
  return std::make_unique<BufferedInputStream>(stream, bufferSize);
}

std::unique_ptr<OutputStream> Streams::GetBufferedOutputStream(
    const std::shared_ptr<OutputStream>& stream, uint64_t bufferSize) {
  return std::make_unique<BufferedOutputStream>(stream, bufferSize);
}

std::unique_ptr<Stream> Streams::GetBufferedStream(
    const std::shared_ptr<Stream>& stream, uint64_t bufferSize) {
  return std::make_unique<BufferedStream>(stream, bufferSize);
}

#if defined(UNICODE) || defined(_UNICODE)
std::unique_ptr<InputStream> Streams::GetFileInputStream(
    const std::wstring& file, bool binaryMode) {
  return std::make_unique<FileInputStream>(file, binaryMode);
}

std::unique_ptr<OutputStream> Streams::GetFileOutputStream(
    const std::wstring& file, bool binaryMode) {
  return std::make_unique<FileOutputStream>(file, binaryMode);
}

std::unique_ptr<Stream> Streams::GetFileStream(const std::wstring& file,
                                               bool binaryMode) {
  return std::make_unique<FileStream>(file, binaryMode);
}
#else

std::unique_ptr<InputStream> Streams::GetFileInputStream(
    const std::string& file, bool binaryMode) {
  return std::make_unique<FileInputStream>(file, binaryMode);
}

std::unique_ptr<OutputStream> Streams::GetFileOutputStream(
    const std::string& file, bool binaryMode) {
  return std::make_unique<FileOutputStream>(file, binaryMode);
}

std::unique_ptr<Stream> Streams::GetFileStream(const std::string& file,
                                               bool binaryMode) {
  return std::make_unique<FileStream>(file, binaryMode);
}
#endif

std::unique_ptr<InputStream> Streams::GetSocketInputStream(
    boost::asio::ip::tcp::socket&& socket) {
  return std::make_unique<SocketInputStream>(std::move(socket));
}

std::unique_ptr<OutputStream> Streams::GetSocketOutputStream(
    boost::asio::ip::tcp::socket&& socket) {
  return std::make_unique<SocketOutputStream>(std::move(socket));
}

std::unique_ptr<Stream> Streams::GetSocketStream(
    boost::asio::ip::tcp::socket&& socket) {
  return std::make_unique<SocketStream>(std::move(socket));
}
