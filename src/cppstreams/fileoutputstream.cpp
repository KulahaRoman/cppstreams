#include "fileoutputstream.h"

namespace CppStreams {
FileOutputStream::FileOutputStream(const std::string& file, bool binary)
    : AbstractFileStream(
          file, std::ios::out |
                    (binary ? std::ios::binary : std::ios::openmode(0))) {}
}  // namespace CppStreams
