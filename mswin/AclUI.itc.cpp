#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <AclUI.h>
#include <PrSht.h>

#include "PrSht.itc.h"
#include "AclUI.itc.h"

namespace itc {

const SingleBit2Val_st _b2v_Aclui_SI_xxx[] =
{
//	ITC_NAMEPAIR(SI_EDIT_PERMS               ), // 0x00000000L // always implied
	ITC_NAMEPAIR(SI_EDIT_OWNER               ), // 0x00000001L
	ITC_NAMEPAIR(SI_EDIT_AUDITS              ), // 0x00000002L
	ITC_NAMEPAIR(SI_CONTAINER                ), // 0x00000004L
	ITC_NAMEPAIR(SI_READONLY                 ), // 0x00000008L
	ITC_NAMEPAIR(SI_ADVANCED                 ), // 0x00000010L
	ITC_NAMEPAIR(SI_RESET                    ), // 0x00000020L //equals to SI_RESET_DACL|SI_RESET_SACL|SI_RESET_OWNER
	ITC_NAMEPAIR(SI_OWNER_READONLY           ), // 0x00000040L
	ITC_NAMEPAIR(SI_EDIT_PROPERTIES          ), // 0x00000080L
	ITC_NAMEPAIR(SI_OWNER_RECURSE            ), // 0x00000100L
	ITC_NAMEPAIR(SI_NO_ACL_PROTECT           ), // 0x00000200L
	ITC_NAMEPAIR(SI_NO_TREE_APPLY            ), // 0x00000400L
	ITC_NAMEPAIR(SI_PAGE_TITLE               ), // 0x00000800L
	ITC_NAMEPAIR(SI_SERVER_IS_DC             ), // 0x00001000L
	ITC_NAMEPAIR(SI_RESET_DACL_TREE          ), // 0x00004000L
	ITC_NAMEPAIR(SI_RESET_SACL_TREE          ), // 0x00008000L
	ITC_NAMEPAIR(SI_OBJECT_GUID              ), // 0x00010000L
	ITC_NAMEPAIR(SI_EDIT_EFFECTIVE           ), // 0x00020000L
	ITC_NAMEPAIR(SI_RESET_DACL               ), // 0x00040000L
	ITC_NAMEPAIR(SI_RESET_SACL               ), // 0x00080000L
	ITC_NAMEPAIR(SI_RESET_OWNER              ), // 0x00100000L
	ITC_NAMEPAIR(SI_NO_ADDITIONAL_PERMISSION ), // 0x00200000L
	ITC_NAMEPAIR(SI_VIEW_ONLY                ), // 0x00400000L
	ITC_NAMEPAIR(SI_PERMS_ELEVATION_REQUIRED ), // 0x01000000L
	ITC_NAMEPAIR(SI_AUDITS_ELEVATION_REQUIRED), // 0x02000000L
	ITC_NAMEPAIR(SI_OWNER_ELEVATION_REQUIRED ), // 0x04000000L
	ITC_NAMEPAIR(SI_MAY_WRITE                ), // 0x10000000L //not sure if user can write permission
};
CInterpretConst Aclui_SI_xxx(_b2v_Aclui_SI_xxx, ITCF_HEX4B);


const Enum2Val_st _e2v_CSecurityInformation_PrshtWmsg[] =
{
	ITC_NAMEPAIR(PSPCB_SI_INITDIALOG), // WM_USER+1
};
CInterpretConst Aclui_PSPCB_xxx(new Enum2Val_merge(
	_e2v_CSecurityInformation_PrshtWmsg, ARRAYSIZE(_e2v_CSecurityInformation_PrshtWmsg),
	_e2v_PSPCB_xxx_wmsg, _e2v_PSPCB_xxx_wmsg_size,
	nullptr, 0), ITCF_UINT);


const Enum2Val_st _e2v_CSecurityInformation_PrshtPageType[] =
{
	ITC_NAMEPAIR(SI_PAGE_PERM),
	ITC_NAMEPAIR(SI_PAGE_ADVPERM),
	ITC_NAMEPAIR(SI_PAGE_AUDIT),
	ITC_NAMEPAIR(SI_PAGE_OWNER),
	ITC_NAMEPAIR(SI_PAGE_EFFECTIVE),
	ITC_NAMEPAIR(SI_PAGE_TAKEOWNERSHIP),
};
CInterpretConst Aclui_SI_PAGE_xxx(_e2v_CSecurityInformation_PrshtPageType, ITCF_UINT);


} //namespace itc
