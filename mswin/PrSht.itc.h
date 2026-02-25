#ifndef CHHI__PrSht_h_20260225_
#define CHHI__PrSht_h_20260225_

#include <InterpretConst.h>

namespace itc {

extern const Enum2Val_st _e2v_PSPCB_xxx_wmsg[];
extern const int _e2v_PSPCB_xxx_wmsg_size;

extern CInterpretConst PSPCB_xxx;

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
#if defined(PrSht_IMPL) || (defined CHHI_ALL_IMPL && !defined CHHI_ALL_IMPL_HIDE_PrSht) // [IMPL] begin
// [IMPL] //
// [IMPL] //
// Include system/OS headers here
// ...
// [IMPL] //
// [IMPL] //
namespace itc {

// More ctor reference: My evclip 20250411.v1


	const Enum2Val_st _e2v_PSPCB_xxx_wmsg[] =
{
	ITC_NAMEPAIR(PSPCB_ADDREF),   // 0
	ITC_NAMEPAIR(PSPCB_RELEASE),  // 1
	ITC_NAMEPAIR(PSPCB_CREATE),   // 2
};
const int _e2v_PSPCB_xxx_wmsg_size = ARRAYSIZE(_e2v_PSPCB_xxx_wmsg);
CInterpretConst PSPCB_xxx(_e2v_PSPCB_xxx_wmsg, ITCF_UINT);



} // namespace itc
// [IMPL] //
// [IMPL] //
#endif // [IMPL] end


#endif // CHHI__PrSht_h_20260225_
