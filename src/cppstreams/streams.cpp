#include "Streams.h"

std::shared_ptr<InputStream> Streams::GetEncryptedInputStream(
    const std::shared_ptr<Encryptor>& encryptor,
    const std::shared_ptr<InputStream>& stream) {
  return std::make_shared<EncryptedInputStream>(encryptor, stream);
}

std::shared_ptr<OutputStream> Streams::GetEncryptedOutputStream(
    const std::shared_ptr<Encryptor>& encryptor,
    const std::shared_ptr<OutputStream>& stream) {
  return std::make_shared<EncryptedOutputStream>(encryptor, stream);
}

std::shared_ptr<Stream> Streams::GetEncryptedStream(
    const std::shared_ptr<Encryptor>& encryptor,
    const std::shared_ptr<Stream>& stream) {
  return std::make_shared<EncryptedStream>(encryptor, stream);
}

std::shared_ptr<InputStream> Streams::GetBufferedInputStream(
    const std::shared_ptr<InputStream>& stream, uint64_t bufferSize) {
  return std::make_shared<BufferedInputStream>(stream, bufferSize);
}

std::shared_ptr<OutputStream> Streams::GetBufferedOutputStream(
    const std::shared_ptr<OutputStream>& stream, uint64_t bufferSize) {
  return std::make_shared<BufferedOutputStream>(stream, bufferSize);
}

std::shared_ptr<Stream> Streams::GetBufferedStream(
    const std::shared_ptr<Stream>& stream, uint64_t bufferSize) {
  return std::make_shared<BufferedStream>(stream, bufferSize);
}

std::shared_ptr<InputStream> Streams::GetFileInputStream(
    const std::string& file, bool binaryMode) {
  return std::make_shared<FileInputStream>(file, binaryMode);
}

std::shared_ptr<OutputStream> Streams::GetFileOutputStream(
    const std::string& file, bool binaryMode) {
  return std::make_shared<FileOutputStream>(file, binaryMode);
}

std::shared_ptr<Stream> Streams::GetFileStream(const std::string& file,
                                               bool binaryMode) {
  return std::make_shared<FileStream>(file, binaryMode);
}

std::shared_ptr<InputStream> Streams::GetSocketInputStream(
    boost::asio::ip::tcp::socket&& socket) {
  return std::make_shared<SocketInputStream>(std::move(socket));
}

std::shared_ptr<OutputStream> Streams::GetSocketOutputStream(
    boost::asio::ip::tcp::socket&& socket) {
  return std::make_shared<SocketOutputStream>(std::move(socket));
}

std::shared_ptr<Stream> Streams::GetSocketStream(
    boost::asio::ip::tcp::socket&& socket) {
  return std::make_shared<SocketStream>(std::move(socket));
}
