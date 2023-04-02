#pragma once
#include <fstream>
#include <iostream>
#include <stdexcept>

class AbstractFileStream {
 protected:
  AbstractFileStream();
  AbstractFileStream(const std::string& file,
                     const std::ios::openmode& openMode);
  ~AbstractFileStream();

 protected:
  std::fstream file;
};
