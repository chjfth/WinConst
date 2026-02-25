#ifndef CHHI__Dbt_h_20260225_
#define CHHI__Dbt_h_20260225_

#include <InterpretConst.h>

namespace itc {

extern const CInterpretConst DBT_xxx;

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
#if defined(Dbt_IMPL) || (defined CHHI_ALL_IMPL && !defined CHHI_ALL_IMPL_HIDE_Dbt) // [IMPL] begin
// [IMPL] //
// [IMPL] //
// Include system/OS headers here
#include <Dbt.h>
// [IMPL] //
// [IMPL] //
namespace itc {

// More ctor reference: My evclip 20250411.v1


const Enum2Val_st _e2v_DBT_xxx[] =
{
	ITC_NAMEPAIR(DBT_DEVICEARRIVAL           ), // 0x8000  // system detected a new device
	ITC_NAMEPAIR(DBT_DEVICEQUERYREMOVE       ), // 0x8001  // wants to remove, may fail
	ITC_NAMEPAIR(DBT_DEVICEQUERYREMOVEFAILED ), // 0x8002  // removal aborted
	ITC_NAMEPAIR(DBT_DEVICEREMOVEPENDING     ), // 0x8003  // about to remove, still avail.
	ITC_NAMEPAIR(DBT_DEVICEREMOVECOMPLETE    ), // 0x8004  // device is gone
	ITC_NAMEPAIR(DBT_DEVICETYPESPECIFIC      ), // 0x8005  // type specific event
	
	ITC_NAMEPAIR(DBT_CUSTOMEVENT             ), // 0x8006  // user-defined event

#ifdef DBT_DEVINSTENUMERATED // These 4 exists in Win7SDK, not disappears in Win10SDK.
	ITC_NAMEPAIR(DBT_DEVINSTENUMERATED       ), // 0x8007  // system detected a new device
	ITC_NAMEPAIR(DBT_DEVINSTSTARTED          ), // 0x8008  // device installed and started
	ITC_NAMEPAIR(DBT_DEVINSTREMOVED          ), // 0x8009  // device removed from system
	ITC_NAMEPAIR(DBT_DEVINSTPROPERTYCHANGED  ), // 0x800A  // a property on the device changed
#endif
};
const CInterpretConst DBT_xxx(_e2v_DBT_xxx, ITCF_HEX2B);


} // namespace itc
// [IMPL] //
// [IMPL] //
#endif // [IMPL] end


#endif // CHHI__Dbt_h_20260225_
