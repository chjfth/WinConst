#pragma once

#include "../itc/InterpretConst.h"

namespace itc {


extern const Enum2Val_st _e2v_WinError[];
extern const int N_e2v_WinError;
extern CInterpretConst WinError;


} // namespace itc

#define ITCS_WinError ITCSvn(GetLastError(), itc::WinError)
