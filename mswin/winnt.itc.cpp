#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "winnt.itc.h"

namespace itc {

const Enum2Val_st e2v_SidType[] =
{
	ITC_NAMEPAIR(SidTypeUser),    // 1
	ITC_NAMEPAIR(SidTypeGroup),    // 2
	ITC_NAMEPAIR(SidTypeDomain),    // 3
	ITC_NAMEPAIR(SidTypeAlias),    // 4
	ITC_NAMEPAIR(SidTypeWellKnownGroup),    // 5
	ITC_NAMEPAIR(SidTypeDeletedAccount),    // 6
	ITC_NAMEPAIR(SidTypeInvalid),    // 7
	ITC_NAMEPAIR(SidTypeUnknown),    // 8
	ITC_NAMEPAIR(SidTypeComputer),    // 9
	ITC_NAMEPAIR(SidTypeLabel),    // 10
};
CInterpretConst SidTypeXXX(e2v_SidType, ARRAYSIZE(e2v_SidType), ITCF_SINT);


const SingleBit2Val_st _b2v_GenericRight[] =
{
	ITC_NAMEPAIR(GENERIC_READ),    // (0x80000000L)
	ITC_NAMEPAIR(GENERIC_WRITE),   // (0x40000000L)
	ITC_NAMEPAIR(GENERIC_EXECUTE), // (0x20000000L)
	ITC_NAMEPAIR(GENERIC_ALL),     // (0x10000000L)	
};
const int N_b2v_GenericRight = ARRAYSIZE(_b2v_GenericRight);

const SingleBit2Val_st _b2v_StandardRight[] =
{
	ITC_NAMEPAIR(DELETE),       //   (0x00010000L)
	ITC_NAMEPAIR(READ_CONTROL), //   (0x00020000L)
	ITC_NAMEPAIR(WRITE_DAC),    //   (0x00040000L)
	ITC_NAMEPAIR(WRITE_OWNER),  //   (0x00080000L)
	ITC_NAMEPAIR(SYNCHRONIZE),  //   (0x00100000L)
};
const int N_b2v_StandardRight = ARRAYSIZE(_b2v_StandardRight);

const SingleBit2Val_st _b2v_GenericAndStandardRight[] =
{
	ITC_NAMEPAIR(GENERIC_READ),    // (0x80000000L)
	ITC_NAMEPAIR(GENERIC_WRITE),   // (0x40000000L)
	ITC_NAMEPAIR(GENERIC_EXECUTE), // (0x20000000L)
	ITC_NAMEPAIR(GENERIC_ALL),     // (0x10000000L)	

	ITC_NAMEPAIR(DELETE),       //   (0x00010000L)
	ITC_NAMEPAIR(READ_CONTROL), //   (0x00020000L)
	ITC_NAMEPAIR(WRITE_DAC),    //   (0x00040000L)
	ITC_NAMEPAIR(WRITE_OWNER),  //   (0x00080000L)
	ITC_NAMEPAIR(SYNCHRONIZE),  //   (0x00100000L)
};
const int N_b2v_GenericAndStandardRight = ARRAYSIZE(_b2v_GenericAndStandardRight);


const SingleBit2Val_st _b2v_FileRight[] =
{
	ITC_NAMEPAIR(FILE_READ_DATA),   // 0x0001
	ITC_NAMEPAIR(FILE_WRITE_DATA),  // 0x0002
	ITC_NAMEPAIR(FILE_APPEND_DATA), // 0x0004
	ITC_NAMEPAIR(FILE_READ_EA),     // 0x0008
	ITC_NAMEPAIR(FILE_WRITE_EA),    // 0x0010
	ITC_NAMEPAIR(FILE_EXECUTE),     // 0x0020
	ITC_NAMEPAIR(FILE_READ_ATTRIBUTES), // 0x0080
	ITC_NAMEPAIR(FILE_WRITE_ATTRIBUTES),// 0x0100
};
CInterpretConst FileRights(_b2v_FileRight, _b2v_GenericAndStandardRight, ITCF_HEX1B);


const SingleBit2Val_st _b2v_DirectoryRight[] =
{
	ITC_NAMEPAIR(FILE_LIST_DIRECTORY), // 0x0001
	ITC_NAMEPAIR(FILE_ADD_FILE),       // 0x0002
	ITC_NAMEPAIR(FILE_ADD_SUBDIRECTORY), // 0x0004
	ITC_NAMEPAIR(FILE_READ_EA),     // 0x0008
	ITC_NAMEPAIR(FILE_WRITE_EA),    // 0x0010
	ITC_NAMEPAIR(FILE_TRAVERSE),    // 0x0020
	ITC_NAMEPAIR(FILE_DELETE_CHILD),// 0x0040
	ITC_NAMEPAIR(FILE_READ_ATTRIBUTES), // 0x0080
	ITC_NAMEPAIR(FILE_WRITE_ATTRIBUTES),// 0x0100
};
CInterpretConst DirectoryRights(_b2v_DirectoryRight, _b2v_GenericAndStandardRight, ITCF_HEX1B);


const SingleBit2Val_st _b2v_TokenRight[] =
{
	ITC_NAMEPAIR(TOKEN_ASSIGN_PRIMARY), //   (0x0001)
	ITC_NAMEPAIR(TOKEN_DUPLICATE),      //   (0x0002)
	ITC_NAMEPAIR(TOKEN_IMPERSONATE),    //   (0x0004)
	ITC_NAMEPAIR(TOKEN_QUERY),          //   (0x0008)
	ITC_NAMEPAIR(TOKEN_QUERY_SOURCE),   //   (0x0010)
	ITC_NAMEPAIR(TOKEN_ADJUST_PRIVILEGES), //(0x0020)
	ITC_NAMEPAIR(TOKEN_ADJUST_GROUPS),  //   (0x0040)
	ITC_NAMEPAIR(TOKEN_ADJUST_DEFAULT), //   (0x0080)
	ITC_NAMEPAIR(TOKEN_ADJUST_SESSIONID),  //(0x0100)
};
CInterpretConst TokenRights(_b2v_TokenRight, _b2v_GenericAndStandardRight, ITCF_HEX1B);


const SingleBit2Val_st _b2v_ProcessRight[] =
{
	ITC_NAMEPAIR(PROCESS_TERMINATE), //                  (0x0001)  
	ITC_NAMEPAIR(PROCESS_CREATE_THREAD), //              (0x0002)  
	ITC_NAMEPAIR(PROCESS_SET_SESSIONID), //              (0x0004)  
	ITC_NAMEPAIR(PROCESS_VM_OPERATION), //               (0x0008)  
	ITC_NAMEPAIR(PROCESS_VM_READ), //                    (0x0010)  
	ITC_NAMEPAIR(PROCESS_VM_WRITE), //                   (0x0020)  
	ITC_NAMEPAIR(PROCESS_DUP_HANDLE), //                 (0x0040)  
	ITC_NAMEPAIR(PROCESS_CREATE_PROCESS), //             (0x0080)  
	ITC_NAMEPAIR(PROCESS_SET_QUOTA), //                  (0x0100)  
	ITC_NAMEPAIR(PROCESS_SET_INFORMATION), //            (0x0200)  
	ITC_NAMEPAIR(PROCESS_QUERY_INFORMATION), //          (0x0400)  
	ITC_NAMEPAIR(PROCESS_SUSPEND_RESUME), //             (0x0800)  
	ITC_NAMEPAIR(PROCESS_QUERY_LIMITED_INFORMATION), //  (0x1000)  
};
CInterpretConst ProcessRights(_b2v_ProcessRight, _b2v_GenericAndStandardRight, ITCF_HEX1B);


const SingleBit2Val_st _b2v_ThreadRight[] =
{
	ITC_NAMEPAIR(THREAD_TERMINATE), //                 (0x0001)  
	ITC_NAMEPAIR(THREAD_SUSPEND_RESUME), //            (0x0002)  
	ITC_NAMEPAIR(THREAD_GET_CONTEXT), //               (0x0008)  
	ITC_NAMEPAIR(THREAD_SET_CONTEXT), //               (0x0010)  
	ITC_NAMEPAIR(THREAD_QUERY_INFORMATION), //         (0x0040)  
	ITC_NAMEPAIR(THREAD_SET_INFORMATION), //           (0x0020)  
	ITC_NAMEPAIR(THREAD_SET_THREAD_TOKEN), //          (0x0080)
	ITC_NAMEPAIR(THREAD_IMPERSONATE), //               (0x0100)
	ITC_NAMEPAIR(THREAD_DIRECT_IMPERSONATION), //      (0x0200)
	ITC_NAMEPAIR(THREAD_SET_LIMITED_INFORMATION), //   (0x0400)  // winnt
	ITC_NAMEPAIR(THREAD_QUERY_LIMITED_INFORMATION), // (0x0800)  // winnt
};
CInterpretConst ThreadRights(_b2v_ThreadRight, _b2v_GenericAndStandardRight, ITCF_HEX1B);


const SingleBit2Val_st _b2v_JobRight[] =
{
	ITC_NAMEPAIR(JOB_OBJECT_ASSIGN_PROCESS), //           (0x0001)
	ITC_NAMEPAIR(JOB_OBJECT_SET_ATTRIBUTES), //           (0x0002)
	ITC_NAMEPAIR(JOB_OBJECT_QUERY), //                    (0x0004)
	ITC_NAMEPAIR(JOB_OBJECT_TERMINATE), //                (0x0008)
	ITC_NAMEPAIR(JOB_OBJECT_SET_SECURITY_ATTRIBUTES), //  (0x0010)
};
CInterpretConst JobRights(_b2v_JobRight, _b2v_GenericAndStandardRight, ITCF_HEX1B);



const SingleBit2Val_st _b2v_xxx_SECURITY_INFORMATION[] =
{
	ITC_NAMEPAIR(OWNER_SECURITY_INFORMATION           ), // 0x01
	ITC_NAMEPAIR(GROUP_SECURITY_INFORMATION           ), // 0x02
	ITC_NAMEPAIR(DACL_SECURITY_INFORMATION            ), // 0x04
	ITC_NAMEPAIR(SACL_SECURITY_INFORMATION            ), // 0x08
	ITC_NAMEPAIR(LABEL_SECURITY_INFORMATION           ), // 0x10

	ITC_NAMEPAIR(PROTECTED_DACL_SECURITY_INFORMATION  ), // 0x80000000
	ITC_NAMEPAIR(PROTECTED_SACL_SECURITY_INFORMATION  ), // 0x40000000
	ITC_NAMEPAIR(UNPROTECTED_DACL_SECURITY_INFORMATION), // 0x20000000
	ITC_NAMEPAIR(UNPROTECTED_SACL_SECURITY_INFORMATION), // 0x10000000
};
CInterpretConst xxx_SECURITY_INFORMATION(_b2v_xxx_SECURITY_INFORMATION, ITCF_HEX1B);


const Enum2Val_st _e2v_xxx_ACE_TYPE[] =
{
	ITC_NAMEPAIR(ACCESS_ALLOWED_ACE_TYPE                 ), // 0
	ITC_NAMEPAIR(ACCESS_DENIED_ACE_TYPE                  ), // 1
	ITC_NAMEPAIR(SYSTEM_AUDIT_ACE_TYPE                   ), // 2
	ITC_NAMEPAIR(SYSTEM_ALARM_ACE_TYPE                   ), // 3
	ITC_NAMEPAIR(ACCESS_ALLOWED_COMPOUND_ACE_TYPE        ), // 4
	ITC_NAMEPAIR(ACCESS_ALLOWED_OBJECT_ACE_TYPE          ), // 5
	ITC_NAMEPAIR(ACCESS_DENIED_OBJECT_ACE_TYPE           ), // 6
	ITC_NAMEPAIR(SYSTEM_AUDIT_OBJECT_ACE_TYPE            ), // 7
	ITC_NAMEPAIR(SYSTEM_ALARM_OBJECT_ACE_TYPE            ), // 8
	ITC_NAMEPAIR(ACCESS_ALLOWED_CALLBACK_ACE_TYPE        ), // 9
	ITC_NAMEPAIR(ACCESS_DENIED_CALLBACK_ACE_TYPE         ), // 10
	ITC_NAMEPAIR(ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE ), // 11
	ITC_NAMEPAIR(ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE  ), // 12
	ITC_NAMEPAIR(SYSTEM_AUDIT_CALLBACK_ACE_TYPE          ), // 13
	ITC_NAMEPAIR(SYSTEM_ALARM_CALLBACK_ACE_TYPE          ), // 14
	ITC_NAMEPAIR(SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE   ), // 15
	ITC_NAMEPAIR(SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE   ), // 16
	ITC_NAMEPAIR(SYSTEM_MANDATORY_LABEL_ACE_TYPE         ), // 17
};
CInterpretConst xxx_ACE_TYPE(_e2v_xxx_ACE_TYPE, ITCF_SINT); // oldname
CInterpretConst AceType(_e2v_xxx_ACE_TYPE, ITCF_SINT);

const SingleBit2Val_st _b2v_ACE_flags[] =
{
	ITC_NAMEPAIR(OBJECT_INHERIT_ACE         ), // 0x01
	ITC_NAMEPAIR(CONTAINER_INHERIT_ACE      ), // 0x02
	ITC_NAMEPAIR(NO_PROPAGATE_INHERIT_ACE   ), // 0x04
	ITC_NAMEPAIR(INHERIT_ONLY_ACE           ), // 0x08
	ITC_NAMEPAIR(INHERITED_ACE              ), // 0x10
	ITC_NAMEPAIR(SUCCESSFUL_ACCESS_ACE_FLAG ), // 0x40
	ITC_NAMEPAIR(FAILED_ACCESS_ACE_FLAG     ), // 0x80
};
CInterpretConst xxx_ACE_flags(_b2v_ACE_flags, ITCF_HEX1B); // oldname
CInterpretConst AceFlags(_b2v_ACE_flags, ITCF_HEX1B);


const SingleBit2Val_st _b2v_SECURITY_DESCRIPTOR_control[] =
{
	ITC_NAMEPAIR(SE_OWNER_DEFAULTED      ), // 0x0001
	ITC_NAMEPAIR(SE_GROUP_DEFAULTED      ), // 0x0002
	ITC_NAMEPAIR(SE_DACL_PRESENT         ), // 0x0004
	ITC_NAMEPAIR(SE_DACL_DEFAULTED       ), // 0x0008
	ITC_NAMEPAIR(SE_SACL_PRESENT         ), // 0x0010
	ITC_NAMEPAIR(SE_SACL_DEFAULTED       ), // 0x0020
	ITC_NAMEPAIR(SE_DACL_AUTO_INHERIT_REQ), // 0x0100
	ITC_NAMEPAIR(SE_SACL_AUTO_INHERIT_REQ), // 0x0200
	ITC_NAMEPAIR(SE_DACL_AUTO_INHERITED  ), // 0x0400
	ITC_NAMEPAIR(SE_SACL_AUTO_INHERITED  ), // 0x0800
	ITC_NAMEPAIR(SE_DACL_PROTECTED       ), // 0x1000
	ITC_NAMEPAIR(SE_SACL_PROTECTED       ), // 0x2000
	ITC_NAMEPAIR(SE_RM_CONTROL_VALID     ), // 0x4000
	ITC_NAMEPAIR(SE_SELF_RELATIVE        ), // 0x8000
};
CInterpretConst SE_xxx_sdControl(_b2v_SECURITY_DESCRIPTOR_control, ITCF_HEX2B);


const SingleBit2Val_st _b2v_SYSTEM_MANDATORY_LABEL_NO_xxx[] =
{
	ITC_NAMEPAIR(SYSTEM_MANDATORY_LABEL_NO_WRITE_UP), //         0x1
	ITC_NAMEPAIR(SYSTEM_MANDATORY_LABEL_NO_READ_UP), //          0x2
	ITC_NAMEPAIR(SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP) //       0x4
};
CInterpretConst SYSTEM_MANDATORY_LABEL_NO_xxx(_b2v_SYSTEM_MANDATORY_LABEL_NO_xxx, ITCF_HEX1B);


const SingleBit2Val_st _b2v_dwShareMode[] =
{
	ITC_NAMEPAIR(FILE_SHARE_READ),   // 0x01
	ITC_NAMEPAIR(FILE_SHARE_WRITE),  // 0x02
	ITC_NAMEPAIR(FILE_SHARE_DELETE), // 0x04
};
CInterpretConst dwShareMode(_b2v_dwShareMode, ITCF_HEX1B);


const Enum2Val_st _e2v_dwCreationDisposition[] =
{
	ITC_NAMEPAIR(CREATE_NEW), //          1
	ITC_NAMEPAIR(CREATE_ALWAYS), //       2
	ITC_NAMEPAIR(OPEN_EXISTING), //       3
	ITC_NAMEPAIR(OPEN_ALWAYS), //         4
	ITC_NAMEPAIR(TRUNCATE_EXISTING), //   5
};
CInterpretConst dwCreationDisposition(_e2v_dwCreationDisposition, ITCF_UINT);


const SingleBit2Val_st _b2v_dwFlagsAndAttributes[] =
{
	ITC_NAMEPAIR(FILE_ATTRIBUTE_READONLY), //             0x00000001  
	ITC_NAMEPAIR(FILE_ATTRIBUTE_HIDDEN), //               0x00000002  
	ITC_NAMEPAIR(FILE_ATTRIBUTE_SYSTEM), //               0x00000004  
	ITC_NAMEPAIR(FILE_ATTRIBUTE_DIRECTORY), //            0x00000010  
	ITC_NAMEPAIR(FILE_ATTRIBUTE_ARCHIVE), //              0x00000020  
	ITC_NAMEPAIR(FILE_ATTRIBUTE_DEVICE), //               0x00000040  
	ITC_NAMEPAIR(FILE_ATTRIBUTE_NORMAL), //               0x00000080  
	ITC_NAMEPAIR(FILE_ATTRIBUTE_TEMPORARY), //            0x00000100  
	ITC_NAMEPAIR(FILE_ATTRIBUTE_SPARSE_FILE), //          0x00000200  
	ITC_NAMEPAIR(FILE_ATTRIBUTE_REPARSE_POINT), //        0x00000400  
	ITC_NAMEPAIR(FILE_ATTRIBUTE_COMPRESSED), //           0x00000800  
	ITC_NAMEPAIR(FILE_ATTRIBUTE_OFFLINE), //              0x00001000  
	ITC_NAMEPAIR(FILE_ATTRIBUTE_NOT_CONTENT_INDEXED), //  0x00002000  
	ITC_NAMEPAIR(FILE_ATTRIBUTE_ENCRYPTED), //            0x00004000  
	ITC_NAMEPAIR(FILE_ATTRIBUTE_VIRTUAL), //              0x00010000  

	// these are from winbase.h :
	ITC_NAMEPAIR(FILE_FLAG_WRITE_THROUGH), //         0x80000000
	ITC_NAMEPAIR(FILE_FLAG_OVERLAPPED), //            0x40000000
	ITC_NAMEPAIR(FILE_FLAG_NO_BUFFERING), //          0x20000000
	ITC_NAMEPAIR(FILE_FLAG_RANDOM_ACCESS), //         0x10000000
	ITC_NAMEPAIR(FILE_FLAG_SEQUENTIAL_SCAN), //       0x08000000
	ITC_NAMEPAIR(FILE_FLAG_DELETE_ON_CLOSE), //       0x04000000
	ITC_NAMEPAIR(FILE_FLAG_BACKUP_SEMANTICS), //      0x02000000
	ITC_NAMEPAIR(FILE_FLAG_POSIX_SEMANTICS), //       0x01000000
	ITC_NAMEPAIR(FILE_FLAG_OPEN_REPARSE_POINT), //    0x00200000
	ITC_NAMEPAIR(FILE_FLAG_OPEN_NO_RECALL), //        0x00100000
	ITC_NAMEPAIR(FILE_FLAG_FIRST_PIPE_INSTANCE), //   0x00080000
};
CInterpretConst dwFlagsAndAttributes(_b2v_dwFlagsAndAttributes, ITCF_HEX4B);


const Enum2Val_st _e2v_SECURITY_IMPERSONATION_LEVEL[] =
{
	ITC_NAMEPAIR(SecurityAnonymous),
	ITC_NAMEPAIR(SecurityIdentification),
	ITC_NAMEPAIR(SecurityImpersonation),
	ITC_NAMEPAIR(SecurityDelegation),
};
CInterpretConst SecurityXXX_ImpersonationLevel(_e2v_SECURITY_IMPERSONATION_LEVEL, ITCF_SINT);
CInterpretConst itc_SECURITY_IMPERSONATION_LEVEL(_e2v_SECURITY_IMPERSONATION_LEVEL);


const Enum2Val_st _e2v_TOKEN_ELEVATION_TYPE[] =
{
	ITC_NAMEPAIR(TokenElevationTypeDefault), // = 1,
	ITC_NAMEPAIR(TokenElevationTypeFull),
	ITC_NAMEPAIR(TokenElevationTypeLimited)
};
CInterpretConst TokenElevationTypeXXX(_e2v_TOKEN_ELEVATION_TYPE, ITCF_SINT);


const SingleBit2Val_st _b2v_SE_GROUP_xxx[] =
{
	ITC_NAMEPAIR(SE_GROUP_MANDATORY         ), // (0x00000001L)
	ITC_NAMEPAIR(SE_GROUP_ENABLED_BY_DEFAULT), // (0x00000002L)
	ITC_NAMEPAIR(SE_GROUP_ENABLED           ), // (0x00000004L)
	ITC_NAMEPAIR(SE_GROUP_OWNER             ), // (0x00000008L)
	ITC_NAMEPAIR(SE_GROUP_USE_FOR_DENY_ONLY ), // (0x00000010L)
	ITC_NAMEPAIR(SE_GROUP_INTEGRITY         ), // (0x00000020L)
	ITC_NAMEPAIR(SE_GROUP_INTEGRITY_ENABLED ), // (0x00000040L)
	ITC_NAMEPAIR(SE_GROUP_LOGON_ID          ), // (0xC0000000L)
	ITC_NAMEPAIR(SE_GROUP_RESOURCE          ), // (0x20000000L)
};
CInterpretConst SE_GROUP_xxx(_b2v_SE_GROUP_xxx, ITCF_HEX1B);


const Enum2Val_st _e2v_TOKEN_TYPE[] =
{
	ITC_NAMEPAIR(TokenPrimary), // = 1
	ITC_NAMEPAIR(TokenImpersonation), // = 2
};
CInterpretConst itc_TOKEN_TYPE(_e2v_TOKEN_TYPE);




} //namespace itc
