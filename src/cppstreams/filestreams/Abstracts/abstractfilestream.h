#pragma once
#include <cpputils/exceptions/exceptions.h>

#include <fstream>
#include <iostream>

class AbstractFileStream {
 protected:
  AbstractFileStream();
  AbstractFileStream(const std::string& file,
                     const std::ios::openmode& openMode);
  ~AbstractFileStream();

 protected:
  std::fstream file;
};
