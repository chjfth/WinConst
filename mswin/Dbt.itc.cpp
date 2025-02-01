#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <Dbt.h>

#include "Dbt.itc.h"

namespace itc {


const Enum2Val_st _e2v_DBT_xxx[] =
{
	ITC_NAMEPAIR(DBT_DEVICEARRIVAL           ), // 0x8000  // system detected a new device
	ITC_NAMEPAIR(DBT_DEVICEQUERYREMOVE       ), // 0x8001  // wants to remove, may fail
	ITC_NAMEPAIR(DBT_DEVICEQUERYREMOVEFAILED ), // 0x8002  // removal aborted
	ITC_NAMEPAIR(DBT_DEVICEREMOVEPENDING     ), // 0x8003  // about to remove, still avail.
	ITC_NAMEPAIR(DBT_DEVICEREMOVECOMPLETE    ), // 0x8004  // device is gone
	ITC_NAMEPAIR(DBT_DEVICETYPESPECIFIC      ), // 0x8005  // type specific event
	
	ITC_NAMEPAIR(DBT_CUSTOMEVENT             ), // 0x8006  // user-defined event
	
	ITC_NAMEPAIR(DBT_DEVINSTENUMERATED       ), // 0x8007  // system detected a new device
	ITC_NAMEPAIR(DBT_DEVINSTSTARTED          ), // 0x8008  // device installed and started
	ITC_NAMEPAIR(DBT_DEVINSTREMOVED          ), // 0x8009  // device removed from system
	ITC_NAMEPAIR(DBT_DEVINSTPROPERTYCHANGED  ), // 0x800A  // a property on the device changed
};
CInterpretConst DBT_xxx(_e2v_DBT_xxx, ITCF_HEX2B);





} //namespace itc
