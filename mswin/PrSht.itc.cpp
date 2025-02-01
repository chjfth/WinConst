#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <PrSht.h>

#include "PrSht.itc.h"

namespace itc {


const Enum2Val_st _e2v_PSPCB_xxx_wmsg[] =
{
	ITC_NAMEPAIR(PSPCB_ADDREF),   // 0
	ITC_NAMEPAIR(PSPCB_RELEASE),  // 1
	ITC_NAMEPAIR(PSPCB_CREATE),   // 2
};
const int _e2v_PSPCB_xxx_wmsg_size = ARRAYSIZE(_e2v_PSPCB_xxx_wmsg);
CInterpretConst PSPCB_xxx(_e2v_PSPCB_xxx_wmsg, ITCF_UINT);



} //namespace itc
