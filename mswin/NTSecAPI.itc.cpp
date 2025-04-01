#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <NTSecAPI.h>

#include "AccCtrl.itc.h"

namespace itc {

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
CInterpretConst SECURITY_LOGON_TYPE(_e2v_SECURITY_LOGON_TYPE, ITCF_SINT);



} //namespace itc
