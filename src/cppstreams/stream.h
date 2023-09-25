#pragma once
#include "inputstream.h"
#include "outputstream.h"

namespace CppStreams {
class Stream : public InputStream, public OutputStream {};
}  // namespace CppStreams
