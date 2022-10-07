#pragma once
#include "../istream.h"
#include "abstracts/abstractfileinputstream.h"
#include "abstracts/abstractfileoutputstream.h"

class FileStream : private AbstractFileInputStream,
                   private AbstractFileOutputStream,
                   public IStream {
 public:
  FileStream(const
#if defined(UNICODE) || defined(_UNICODE)
             std::wstring
#else
             std::string
#endif
                 & file,
             bool binary);

  uint64_t Read(unsigned char* data, uint64_t size) override;
  uint64_t Available() override;
  uint64_t Skip(uint64_t nBytes) override;

  uint64_t Write(const unsigned char* data, uint64_t size) override;
  uint64_t Flush() override;
};
