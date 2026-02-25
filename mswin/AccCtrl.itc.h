#ifndef CHHI__AccCtrl_h_20260225_
#define CHHI__AccCtrl_h_20260225_

#include <InterpretConst.h>

namespace itc {


extern const CInterpretConst SE_xxx_objectType;


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
#if defined(AccCtrl_IMPL) || (defined CHHI_ALL_IMPL && !defined CHHI_ALL_IMPL_HIDE_AccCtrl) // [IMPL] begin
// [IMPL] //
// [IMPL] //
// Include system/OS headers here
#include <stdio.h>
// [IMPL] //
// [IMPL] //
namespace itc {


// More ctor reference: My evclip 20250411.v1

const Enum2Val_st e2v_SE_OBJECT_TYPE[] =
{
	ITC_NAMEPAIR(SE_UNKNOWN_OBJECT_TYPE),  // 0
	ITC_NAMEPAIR(SE_FILE_OBJECT),          // 1
	ITC_NAMEPAIR(SE_SERVICE),              // 2
	ITC_NAMEPAIR(SE_PRINTER),              // 3
	ITC_NAMEPAIR(SE_REGISTRY_KEY),         // 4
	ITC_NAMEPAIR(SE_LMSHARE),              // 5
	ITC_NAMEPAIR(SE_KERNEL_OBJECT),        // 6
	ITC_NAMEPAIR(SE_WINDOW_OBJECT),        // 7
	ITC_NAMEPAIR(SE_DS_OBJECT),            // 8
	ITC_NAMEPAIR(SE_DS_OBJECT_ALL),        // 9
	ITC_NAMEPAIR(SE_PROVIDER_DEFINED_OBJECT), // 10
	ITC_NAMEPAIR(SE_WMIGUID_OBJECT),       // 11
	ITC_NAMEPAIR(SE_REGISTRY_WOW64_32KEY), // 12
};
const CInterpretConst SE_xxx_objectType(e2v_SE_OBJECT_TYPE, ITCF_SINT);


} // namespace itc
// [IMPL] //
// [IMPL] //
#endif // [IMPL] end


#endif // CHHI__AccCtrl_h_20260225_
