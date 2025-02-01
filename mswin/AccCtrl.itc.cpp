#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <AccCtrl.h>

#include "AccCtrl.itc.h"

namespace itc {

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
CInterpretConst SE_xxx_objectType(e2v_SE_OBJECT_TYPE, ITCF_SINT);



} //namespace itc
