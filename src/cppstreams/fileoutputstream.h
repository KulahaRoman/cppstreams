#pragma once
#include "abstractfileoutputstream.h"

namespace CppStreams {
class FileOutputStream : public AbstractFileOutputStream {
 public:
  FileOutputStream(const std::string& file, bool binary);
};
}  // namespace CppStreams
