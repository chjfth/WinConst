#pragma once

#include "../itc/InterpretConst.h"

namespace itc {


extern CInterpretConst SidTypeXXX;

extern const SingleBit2Val_st _b2v_StandardRight[];
extern const int N_b2v_StandardRight; // needed by WinSvc.itc.cpp etc.

extern CInterpretConst FileRights;
extern CInterpretConst DirectoryRights;
extern CInterpretConst TokenRights;
extern CInterpretConst ProcessRights;
extern CInterpretConst ThreadRights;
extern CInterpretConst JobRights;

extern CInterpretConst xxx_SECURITY_INFORMATION;

extern CInterpretConst xxx_ACE_TYPE;
extern CInterpretConst xxx_ACE_flags;

extern CInterpretConst SE_xxx_sdControl;


} // namespace itc