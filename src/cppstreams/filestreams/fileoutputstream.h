#pragma once
#include "../ioutputstream.h"
#include "abstracts/abstractfileoutputstream.h"

class FileOutputStream : private AbstractFileOutputStream,
                         public IOutputStream {
 public:
  FileOutputStream(const
#if defined(UNICODE) || defined(_UNICODE)
                   std::wstring
#else
                   std::string
#endif
                       & file,
                   bool binary);

  uint64_t Write(const unsigned char* data, uint64_t size) override;
  uint64_t Flush() override;
};
