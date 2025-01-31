#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <LMAccess.h>

#include "LMAccess.itc.h"

namespace itc {

const Enum2Val_st e2v_ACCESS_xxx[] =
{
	ITC_NAMEPAIR(ACCESS_READ),   // 0x01
	ITC_NAMEPAIR(ACCESS_WRITE),  // 0x02
	ITC_NAMEPAIR(ACCESS_CREATE), // 0x04
	ITC_NAMEPAIR(ACCESS_EXEC),   // 0x08
	ITC_NAMEPAIR(ACCESS_DELETE), // 0x10
	ITC_NAMEPAIR(ACCESS_ATRIB),  // 0x20
	ITC_NAMEPAIR(ACCESS_PERM),   // 0x40
};
const SingleBit2Val_st b2v_ACCESS_GROUP[] =
{
	ITC_NAMEPAIR(ACCESS_GROUP)
};
CInterpretConst ACCESS_xxx(ITCF_HEX1B, e2v_ACCESS_xxx, ARRAYSIZE(e2v_ACCESS_xxx),
	b2v_ACCESS_GROUP, ARRAYSIZE(b2v_ACCESS_GROUP),
	nullptr, 0);



} //namespace itc
