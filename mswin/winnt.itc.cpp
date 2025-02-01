#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "winnt.itc.h"

namespace itc {

const Enum2Val_st e2v_SidType[] =
{
	ITC_NAMEPAIR(SidTypeUser),    // 1
	ITC_NAMEPAIR(SidTypeGroup),    // 2
	ITC_NAMEPAIR(SidTypeDomain),    // 3
	ITC_NAMEPAIR(SidTypeAlias),    // 4
	ITC_NAMEPAIR(SidTypeWellKnownGroup),    // 5
	ITC_NAMEPAIR(SidTypeDeletedAccount),    // 6
	ITC_NAMEPAIR(SidTypeInvalid),    // 7
	ITC_NAMEPAIR(SidTypeUnknown),    // 8
	ITC_NAMEPAIR(SidTypeComputer),    // 9
	ITC_NAMEPAIR(SidTypeLabel),    // 10
};
CInterpretConst SidTypeXXX(e2v_SidType, ARRAYSIZE(e2v_SidType), ITCF_SINT);



} //namespace itc
