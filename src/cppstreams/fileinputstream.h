#pragma once
#include "abstractfileinputstream.h"

namespace CppStreams {
class FileInputStream : public AbstractFileInputStream {
 public:
  FileInputStream(const std::string& file, bool binary);
};
}  // namespace CppStreams
