#ifndef __CHHI__LMAccess_h_20260312_
#define __CHHI__LMAccess_h_20260312_

#include <InterpretConst.h>

namespace itc {

extern const CInterpretConst ACCESS_xxx;


} // namespace itc


/*
////////////////////////////////////////////////////////////////////////////
 ___                 _                           _        _   _             
|_ _|_ __ ___  _ __ | | ___ _ __ ___   ___ _ __ | |_ __ _| |_(_) ___  _ __  
 | || '_ ` _ \| '_ \| |/ _ \ '_ ` _ \ / _ \ '_ \| __/ _` | __| |/ _ \| '_ \ 
 | || | | | | | |_) | |  __/ | | | | |  __/ | | | || (_| | |_| | (_) | | | |
|___|_| |_| |_| .__/|_|\___|_| |_| |_|\___|_| |_|\__\__,_|\__|_|\___/|_| |_|
              |_|                                                           
////////////////////////////////////////////////////////////////////////////
*/
// ++++++++++++++++++ Implementation Below ++++++++++++++++++
//
#if defined(LMAccess_itc_IMPL) || (defined CHHI_ALL_IMPL && !defined CHHI_ALL_IMPL_HIDE_LMAccess_itc) // [IMPL] begin
// [IMPL] //
// [IMPL] //
// Include system/OS headers here
//#include <stdio.h>
// [IMPL] //
// [IMPL] //
namespace itc {

// More ctor reference: My evclip 20250411.v1


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
const CInterpretConst ACCESS_xxx(ITCF_HEX1B, e2v_ACCESS_xxx, ARRAYSIZE(e2v_ACCESS_xxx),
	b2v_ACCESS_GROUP, ARRAYSIZE(b2v_ACCESS_GROUP),
	nullptr, 0);



} // namespace itc
// [IMPL] //
// [IMPL] //
#endif // [IMPL] end


#endif // CHHI__LMAccess_h_20260312_
