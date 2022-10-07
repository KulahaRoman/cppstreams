#pragma once
#include "iinputstream.h"
#include "ioutputstream.h"

class IStream : public IInputStream, public IOutputStream {};
