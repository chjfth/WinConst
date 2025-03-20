#pragma once

#include "../itc/InterpretConst.h"

namespace itc {


extern CInterpretConst WinError;


} // namespace itc

#define ITCS_WinError ITCSvn(GetLastError(), itc::WinError)
