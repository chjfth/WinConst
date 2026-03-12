#ifndef __CHHI__NTSecAPI_h_20260312_
#define __CHHI__NTSecAPI_h_20260312_

#include <InterpretConst.h>

namespace itc {

extern const CInterpretConst itc_SECURITY_LOGON_TYPE;

extern const CInterpretConst LOGON_xxx_UserFlags;

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
#if defined(NTSecAPI_itc_IMPL) || (defined CHHI_ALL_IMPL && !defined CHHI_ALL_IMPL_HIDE_NTSecAPI_itc) // [IMPL] begin
// [IMPL] //
// [IMPL] //
// Include system/OS headers here
#include <stdio.h>
// [IMPL] //
// [IMPL] //
namespace itc {

// More ctor reference: My evclip 20250411.v1

const Enum2Val_st _e2v_SECURITY_LOGON_TYPE[] =
{
    ITC_NAMEPAIR(UndefinedLogonType),// =0 This is used to specify an undefied logon type
    ITC_NAMEPAIR(Interactive),       // =2 Interactively logged on (locally or remotely)
    ITC_NAMEPAIR(Network),              // Accessing system via network
    ITC_NAMEPAIR(Batch),                // Started via a batch queue
    ITC_NAMEPAIR(Service),              // Service started by service controller
    ITC_NAMEPAIR(Proxy),                // Proxy logon
    ITC_NAMEPAIR(Unlock),               // Unlock workstation
    ITC_NAMEPAIR(NetworkCleartext),     // Network logon with cleartext credentials
    ITC_NAMEPAIR(NewCredentials),       // Clone caller, new default credentials
    
    //The types below only exist in Windows XP and greater
    ITC_NAMEPAIR(RemoteInteractive),  // Remote, yet interactive. Terminal server
    ITC_NAMEPAIR(CachedInteractive),  // Try cached credentials without hitting the net.
    
    // The types below only exist in Windows Server 2003 and greater
    ITC_NAMEPAIR(CachedRemoteInteractive), // Same as RemoteInteractive, this is used internally for auditing purpose
    ITC_NAMEPAIR(CachedUnlock),        // Cached Unlock workstation
};
const CInterpretConst itc_SECURITY_LOGON_TYPE(_e2v_SECURITY_LOGON_TYPE, ITCF_SINT);


const SingleBit2Val_st _b2v_LogonUserFlags[] =
{
	ITC_NAMEPAIR(LOGON_OPTIMIZED),
	ITC_NAMEPAIR(LOGON_WINLOGON),    
	ITC_NAMEPAIR(LOGON_PKINIT),      
	ITC_NAMEPAIR(LOGON_NO_OPTIMIZED),
};
const CInterpretConst LOGON_xxx_UserFlags(_b2v_LogonUserFlags, ITCF_HEX2B);


} // namespace itc
// [IMPL] //
// [IMPL] //
#endif // [IMPL] end


#endif // CHHI__NTSecAPI_h_20260312_
