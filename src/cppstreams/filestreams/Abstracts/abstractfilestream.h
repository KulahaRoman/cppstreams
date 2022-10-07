#pragma once
#include <cpputils/exceptions/exceptions.h>

#include <fstream>
#include <iostream>

class AbstractFileStream {
 protected:
  AbstractFileStream();
  AbstractFileStream(const
#if defined(UNICODE) || defined(_UNICODE)
                     std::wstring
#else
                     std::string
#endif
                         & file,
                     const std::ios::openmode& openMode);
  ~AbstractFileStream();

 protected:
  std::fstream file;
};
