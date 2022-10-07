#pragma once
#include "../iinputstream.h"
#include "abstracts/abstractfileinputstream.h"

class FileInputStream : private AbstractFileInputStream, public IInputStream {
 public:
  FileInputStream(const
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
};
