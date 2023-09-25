#include <cppstreams/filestream.h>
#include <cpputils/files.h>
#include <gtest/gtest.h>

using namespace CppStreams;
using namespace CppUtils;

TEST(FileStreamTest, WriteAndReadData) {
  std::string file = "test";
  Files::CreateFile(file);

  {
    FileStream stream(file, true);

    std::string out = "Hello, World!";
    stream.Write(reinterpret_cast<const unsigned char*>(out.data()),
                 out.size());

    std::string in(out.size(), '\0');
    stream.Read(reinterpret_cast<unsigned char*>(in.data()), in.size());

    ASSERT_TRUE(out == in);
  }

  Files::Remove(file);
}
