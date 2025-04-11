#pragma once

#include "../itc/InterpretConst.h"

namespace itc {


extern CInterpretConst SidTypeXXX;

extern const SingleBit2Val_st _b2v_GenericRight[];
extern CInterpretConst GenericRight;
extern const int N_b2v_GenericRight;

extern const SingleBit2Val_st _b2v_StandardRight[];
extern CInterpretConst StandardRight;
extern const int N_b2v_StandardRight; // needed by WinSvc.itc.cpp etc.

extern const SingleBit2Val_st _b2v_GenericAndStandardRight[];
extern CInterpretConst GenericAndStandardRight;
extern const int N_b2v_GenericAndStandardRight;

extern const SingleBit2Val_st _b2v_FILE_ATTRIBUTE_xxx[];
extern CInterpretConst FILE_ATTRIBUTE_xxx;
extern const int N_b2v_FILE_ATTRIBUTE_xxx; // used by WinBase dwFlagsAndAttributes


extern CInterpretConst FileRights;
extern CInterpretConst DirectoryRights;
extern CInterpretConst TokenRights;
extern CInterpretConst ProcessRights;
extern CInterpretConst ThreadRights;
extern CInterpretConst JobRights;

extern CInterpretConst xxx_SECURITY_INFORMATION;

extern CInterpretConst xxx_ACE_TYPE; // oldname
extern CInterpretConst AceType;
extern CInterpretConst xxx_ACE_flags; // oldname
extern CInterpretConst AceFlags;

extern CInterpretConst SE_xxx_sdControl;

extern CInterpretConst SYSTEM_MANDATORY_LABEL_NO_xxx;

extern CInterpretConst dwShareMode;

extern CInterpretConst SecurityXXX_ImpersonationLevel;
extern CInterpretConst itc_SECURITY_IMPERSONATION_LEVEL;

extern CInterpretConst TokenElevationTypeXXX;

extern CInterpretConst SE_GROUP_xxx;

extern CInterpretConst itc_TOKEN_TYPE;



} // namespace itc