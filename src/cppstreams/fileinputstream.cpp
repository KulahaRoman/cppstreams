#include "fileinputstream.h"

namespace CppStreams {
FileInputStream::FileInputStream(const std::string& file, bool binary)
    : AbstractFileStream(
          file,
          std::ios::in | (binary ? std::ios::binary : std::ios::openmode(0))) {}
}  // namespace CppStreams
