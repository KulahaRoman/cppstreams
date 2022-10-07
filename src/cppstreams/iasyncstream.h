#pragma once
#include "iasyncinputstream.h"
#include "iasyncoutputstream.h"

class IAsyncStream : public IAsyncInputStream, public IAsyncOutputStream {};
