#define WIN32_LEAN_AND_MEAN
#include <windows.h> 
#include <CommCtrl.h>

#include "winuser.itc.h"
#include "commctrl.itc.h"

namespace itc {

//
// Window style for "SysListView32"
//

const Enum2Val_st _e2v_WS_xxx_SysListView32_TYPE[] =
{
//	ITC_NAMEPAIR(LVS_TYPEMASK),            // 0x0003 (mask)

	ITC_NAMEPAIR(LVS_ICON),                // 0x0000
	ITC_NAMEPAIR(LVS_REPORT),              // 0x0001
	ITC_NAMEPAIR(LVS_SMALLICON),           // 0x0002
	ITC_NAMEPAIR(LVS_LIST),                // 0x0003
};


const Enum2Val_st _e2v_WS_xxx_SysListView32_ALIGN[] =
{
//	ITC_NAMEPAIR(LVS_ALIGNMASK),           // 0x0c00 (mask)

	ITC_NAMEPAIR(LVS_ALIGNTOP),            // 0x0000
	ITC_NAMEPAIR(LVS_ALIGNLEFT),           // 0x0800

	ITC_NAMEPAIR(LVS_OWNERDRAWFIXED),      // 0x0400
};


const SingleBit2Val_st _b2v_WS_xxx_SysListView32[] =
{
	ITC_NAMEPAIR(LVS_SINGLESEL),           // 0x0004
	ITC_NAMEPAIR(LVS_SHOWSELALWAYS),       // 0x0008
	ITC_NAMEPAIR(LVS_SORTASCENDING),       // 0x0010
	ITC_NAMEPAIR(LVS_SORTDESCENDING),      // 0x0020
	ITC_NAMEPAIR(LVS_SHAREIMAGELISTS),     // 0x0040
	ITC_NAMEPAIR(LVS_NOLABELWRAP),         // 0x0080
	ITC_NAMEPAIR(LVS_AUTOARRANGE),         // 0x0100
	ITC_NAMEPAIR(LVS_EDITLABELS),          // 0x0200
	ITC_NAMEPAIR(LVS_OWNERDATA),           // 0x1000
	ITC_NAMEPAIR(LVS_NOSCROLL),            // 0x2000

	ITC_NAMEPAIR(LVS_NOCOLUMNHEADER),      // 0x4000
	ITC_NAMEPAIR(LVS_NOSORTHEADER),        // 0x8000
};


const EnumGroup_st _egs_WS_xxx_SysListView32[] = 
{
	{ LVS_TYPEMASK,  _e2v_WS_xxx_SysListView32_TYPE,  ARRAYSIZE(_e2v_WS_xxx_SysListView32_TYPE)  },
	{ LVS_ALIGNMASK, _e2v_WS_xxx_SysListView32_ALIGN, ARRAYSIZE(_e2v_WS_xxx_SysListView32_ALIGN) },
};
CInterpretConst WS_xxx_SysListView32(ITCF_HEX4B,
	_egs_WS_xxx_SysListView32, ARRAYSIZE(_egs_WS_xxx_SysListView32),
	_b2v_WS_xxx_SysListView32, ARRAYSIZE(_b2v_WS_xxx_SysListView32), 
	_b2v_WS_xxx_childwnd, ARRAYSIZE(_b2v_WS_xxx_childwnd),
	nullptr, 0);


// Extended-style for "SysListView32"
//
const SingleBit2Val_st _b2v_LVS_EX_xxx[] =
{
	ITC_NAMEPAIR(LVS_EX_GRIDLINES),        // 0x00000001
	ITC_NAMEPAIR(LVS_EX_SUBITEMIMAGES),    // 0x00000002
	ITC_NAMEPAIR(LVS_EX_CHECKBOXES),       // 0x00000004
	ITC_NAMEPAIR(LVS_EX_TRACKSELECT),      // 0x00000008
	ITC_NAMEPAIR(LVS_EX_HEADERDRAGDROP),   // 0x00000010
	ITC_NAMEPAIR(LVS_EX_FULLROWSELECT),    // 0x00000020 // applies to report mode only
	ITC_NAMEPAIR(LVS_EX_ONECLICKACTIVATE), // 0x00000040
	ITC_NAMEPAIR(LVS_EX_TWOCLICKACTIVATE), // 0x00000080

	ITC_NAMEPAIR(LVS_EX_FLATSB),           // 0x00000100
	ITC_NAMEPAIR(LVS_EX_REGIONAL),         // 0x00000200
	ITC_NAMEPAIR(LVS_EX_INFOTIP),          // 0x00000400 // listview does InfoTips for you
	ITC_NAMEPAIR(LVS_EX_UNDERLINEHOT),     // 0x00000800
	ITC_NAMEPAIR(LVS_EX_UNDERLINECOLD),    // 0x00001000
	ITC_NAMEPAIR(LVS_EX_MULTIWORKAREAS),   // 0x00002000

	ITC_NAMEPAIR(LVS_EX_LABELTIP),         // 0x00004000 // listview unfolds partly hidden labels if it does not have infotip text
	ITC_NAMEPAIR(LVS_EX_BORDERSELECT),     // 0x00008000 // border selection style instead of highlight

	ITC_NAMEPAIR(LVS_EX_DOUBLEBUFFER),     // 0x00010000
	ITC_NAMEPAIR(LVS_EX_HIDELABELS),       // 0x00020000
	ITC_NAMEPAIR(LVS_EX_SINGLEROW),        // 0x00040000
	ITC_NAMEPAIR(LVS_EX_SNAPTOGRID),       // 0x00080000  // Icons automatically snap to grid.
	ITC_NAMEPAIR(LVS_EX_SIMPLESELECT),     // 0x00100000  // Also changes overlay rendering to top right for icon mode.

//#if _WIN32_WINNT >= 0x0600
	ITC_NAMEPAIR(LVS_EX_JUSTIFYCOLUMNS),   // 0x00200000  // Icons are lined up in columns that use up the whole view area.
	ITC_NAMEPAIR(LVS_EX_TRANSPARENTBKGND), // 0x00400000  // Background is painted by the parent via WM_PRINTCLIENT
	ITC_NAMEPAIR(LVS_EX_TRANSPARENTSHADOWTEXT), // 0x00800000  // Enable shadow text on transparent backgrounds only (useful with bitmaps)
	ITC_NAMEPAIR(LVS_EX_AUTOAUTOARRANGE),  // 0x01000000  // Icons automatically arrange if no icon positions have been set
	ITC_NAMEPAIR(LVS_EX_HEADERINALLVIEWS), // 0x02000000  // Display column header in all view modes
	ITC_NAMEPAIR(LVS_EX_AUTOCHECKSELECT),  // 0x08000000
	ITC_NAMEPAIR(LVS_EX_AUTOSIZECOLUMNS),  // 0x10000000
	ITC_NAMEPAIR(LVS_EX_COLUMNSNAPPOINTS), // 0x40000000
	ITC_NAMEPAIR(LVS_EX_COLUMNOVERFLOW),   // 0x80000000
//#endif
};
CInterpretConst LVS_EX_xxx(_b2v_LVS_EX_xxx, ITCF_HEX4B);


//
// Window style for "SysTreeView32"
//

const SingleBit2Val_st _b2v_WS_xxx_SysTreeView32[] =
{
	ITC_NAMEPAIR(TVS_HASBUTTONS),          // 0x0001
	ITC_NAMEPAIR(TVS_HASLINES),            // 0x0002
	ITC_NAMEPAIR(TVS_LINESATROOT),         // 0x0004
	ITC_NAMEPAIR(TVS_EDITLABELS),          // 0x0008
	ITC_NAMEPAIR(TVS_DISABLEDRAGDROP),     // 0x0010
	ITC_NAMEPAIR(TVS_SHOWSELALWAYS),       // 0x0020
	ITC_NAMEPAIR(TVS_RTLREADING),          // 0x0040

	ITC_NAMEPAIR(TVS_NOTOOLTIPS),          // 0x0080
	ITC_NAMEPAIR(TVS_CHECKBOXES),          // 0x0100
	ITC_NAMEPAIR(TVS_TRACKSELECT),         // 0x0200

	ITC_NAMEPAIR(TVS_SINGLEEXPAND),        // 0x0400
	ITC_NAMEPAIR(TVS_INFOTIP),             // 0x0800
	ITC_NAMEPAIR(TVS_FULLROWSELECT),       // 0x1000
	ITC_NAMEPAIR(TVS_NOSCROLL),            // 0x2000
	ITC_NAMEPAIR(TVS_NONEVENHEIGHT),       // 0x4000

	ITC_NAMEPAIR(TVS_NOHSCROLL),           // 0x8000  // TVS_NOSCROLL overrides this
};
CInterpretConst WS_xxx_SysTreeView32(ITCF_HEX4B,
	_b2v_WS_xxx_SysTreeView32, ARRAYSIZE(_b2v_WS_xxx_SysTreeView32),
	_b2v_WS_xxx_childwnd, ARRAYSIZE(_b2v_WS_xxx_childwnd),
	nullptr, 0);


// Extended-style for "SysTreeView32"
//
const SingleBit2Val_st _b2v_TVS_EX_xxx[] =
{
//#if (_WIN32_WINNT >= 0x0600)
	ITC_NAMEPAIR(TVS_EX_MULTISELECT),          // 0x0002 (not implemented)
	ITC_NAMEPAIR(TVS_EX_DOUBLEBUFFER),         // 0x0004
	ITC_NAMEPAIR(TVS_EX_NOINDENTSTATE),        // 0x0008
	ITC_NAMEPAIR(TVS_EX_RICHTOOLTIP),          // 0x0010
	ITC_NAMEPAIR(TVS_EX_AUTOHSCROLL),          // 0x0020
	ITC_NAMEPAIR(TVS_EX_FADEINOUTEXPANDOS),    // 0x0040
	ITC_NAMEPAIR(TVS_EX_PARTIALCHECKBOXES),    // 0x0080
	ITC_NAMEPAIR(TVS_EX_EXCLUSIONCHECKBOXES),  // 0x0100
	ITC_NAMEPAIR(TVS_EX_DIMMEDCHECKBOXES),     // 0x0200
	ITC_NAMEPAIR(TVS_EX_DRAWIMAGEASYNC),       // 0x0400
//#endif
};
CInterpretConst TVS_EX_xxx(_b2v_TVS_EX_xxx, ITCF_HEX4B);


//
// Window style for "tooltips_class32"
//

const SingleBit2Val_st _b2v_WS_xxx_tooltips_class32[] =
{
	ITC_NAMEPAIR(TTS_ALWAYSTIP),           // 0x01
	ITC_NAMEPAIR(TTS_NOPREFIX),            // 0x02
	ITC_NAMEPAIR(TTS_NOANIMATE),           // 0x10
	ITC_NAMEPAIR(TTS_NOFADE),              // 0x20
	ITC_NAMEPAIR(TTS_BALLOON),             // 0x40
	ITC_NAMEPAIR(TTS_CLOSE),               // 0x80

//#if _WIN32_WINNT >= 0x0600
	ITC_NAMEPAIR(TTS_USEVISUALSTYLE),      // 0x100  // Use themed hyperlinks
//#endif
};
CInterpretConst WS_xxx_tooltips_class32_toplevel(ITCF_HEX4B,
	_b2v_WS_xxx_tooltips_class32, ARRAYSIZE(_b2v_WS_xxx_tooltips_class32),
	_b2v_WS_xxx_toplevel, ARRAYSIZE(_b2v_WS_xxx_childwnd),
	nullptr, 0);
CInterpretConst WS_xxx_tooltips_class32_childwnd(ITCF_HEX4B,
	_b2v_WS_xxx_tooltips_class32, ARRAYSIZE(_b2v_WS_xxx_tooltips_class32),
	_b2v_WS_xxx_childwnd, ARRAYSIZE(_b2v_WS_xxx_childwnd),
	nullptr, 0);


//
// CommCtrl Notification code
//

const Enum2Val_st _e2v_NM_xxx_Generic[] =
{
	ITC_NAMEPAIR(NM_OUTOFMEMORY         ), // -1
	ITC_NAMEPAIR(NM_CLICK               ), // -2
	ITC_NAMEPAIR(NM_DBLCLK              ), // -3
	ITC_NAMEPAIR(NM_RETURN              ), // -4
	ITC_NAMEPAIR(NM_RCLICK              ), // -5
	ITC_NAMEPAIR(NM_RDBLCLK             ), // -6
	ITC_NAMEPAIR(NM_SETFOCUS            ), // -7
	ITC_NAMEPAIR(NM_KILLFOCUS           ), // -8
	ITC_NAMEPAIR(NM_CUSTOMDRAW          ), // -12
	ITC_NAMEPAIR(NM_HOVER               ), // -13

	ITC_NAMEPAIR(NM_NCHITTEST           ), // -14
	ITC_NAMEPAIR(NM_KEYDOWN             ), // -15
	ITC_NAMEPAIR(NM_RELEASEDCAPTURE     ), // -16
	ITC_NAMEPAIR(NM_SETCURSOR           ), // -17
	ITC_NAMEPAIR(NM_CHAR                ), // -18

	ITC_NAMEPAIR(NM_TOOLTIPSCREATED     ), // -19

	ITC_NAMEPAIR(NM_LDOWN               ), // -20
	ITC_NAMEPAIR(NM_RDOWN               ), // -21
	ITC_NAMEPAIR(NM_THEMECHANGED        ), // -22

	ITC_NAMEPAIR(NM_FONTCHANGED         ), // -23
	ITC_NAMEPAIR(NM_CUSTOMTEXT          ), // -24
//	ITC_NAMEPAIR(NM_TVSTATEIMAGECHANGING), // -24 (looks not generic)
};
CInterpretConst NM_xxx_Generic(_e2v_NM_xxx_Generic, ITCF_SINT);


// + ListView NM_xxx

const Enum2Val_st _e2v_LVN_xxx[]=
{
	ITC_NAMEPAIR(LVN_ITEMCHANGING       ), // -100
	ITC_NAMEPAIR(LVN_ITEMCHANGED        ), // -101
	ITC_NAMEPAIR(LVN_INSERTITEM         ), // -102
	ITC_NAMEPAIR(LVN_DELETEITEM         ), // -103
	ITC_NAMEPAIR(LVN_DELETEALLITEMS     ), // -104
	ITC_NAMEPAIR(LVN_BEGINLABELEDITA    ), // -105
	ITC_NAMEPAIR(LVN_BEGINLABELEDITW    ), // -175
	ITC_NAMEPAIR(LVN_ENDLABELEDITA      ), // -106
	ITC_NAMEPAIR(LVN_ENDLABELEDITW      ), // -176
	ITC_NAMEPAIR(LVN_COLUMNCLICK        ), // -108
	ITC_NAMEPAIR(LVN_BEGINDRAG          ), // -109
	ITC_NAMEPAIR(LVN_BEGINRDRAG         ), // -110
	ITC_NAMEPAIR(LVN_ODCACHEHINT        ), // -113
	ITC_NAMEPAIR(LVN_ODFINDITEMA        ), // -152
	ITC_NAMEPAIR(LVN_ODFINDITEMW        ), // -179
	ITC_NAMEPAIR(LVN_ITEMACTIVATE       ), // -114
	ITC_NAMEPAIR(LVN_ODSTATECHANGED     ), // -115
	
	ITC_NAMEPAIR(LVN_HOTTRACK), // -121
	ITC_NAMEPAIR(LVN_GETDISPINFOA), // -150
	ITC_NAMEPAIR(LVN_SETDISPINFOA), // -151
	ITC_NAMEPAIR(LVN_GETDISPINFOW), // -177
	ITC_NAMEPAIR(LVN_SETDISPINFOW), // -178

	ITC_NAMEPAIR(LVN_KEYDOWN),  // -155
	ITC_NAMEPAIR(LVN_MARQUEEBEGIN), // -156

	ITC_NAMEPAIR(LVN_GETINFOTIPA), // -157
	ITC_NAMEPAIR(LVN_GETINFOTIPW), // -158

	ITC_NAMEPAIR(LVN_BEGINSCROLL), // -180
	ITC_NAMEPAIR(LVN_ENDSCROLL),   // -181

#if _WIN32_WINNT >= 0x0600
	ITC_NAMEPAIR(LVN_COLUMNDROPDOWN),  // -164
	ITC_NAMEPAIR(LVN_COLUMNOVERFLOWCLICK), // -166
	ITC_NAMEPAIR(LVN_LINKCLICK), // -184
	ITC_NAMEPAIR(LVN_GETEMPTYMARKUP), // -187
#endif
};
CInterpretConst LVN_xxx(
	new Enum2Val_merge(
		_e2v_NM_xxx_Generic,  ARRAYSIZE(_e2v_NM_xxx_Generic),
		_e2v_LVN_xxx, ARRAYSIZE(_e2v_LVN_xxx),
		nullptr, 0) // this Enum2Val_merge object will not be deleted, by design
	, ITCF_SINT
	); 
// old name NM_xxx_ListView


// Tooltip, TOOLINFO.uFlags :
const SingleBit2Val_st _b2v_TTF_xxx[] = 
{
	ITC_NAMEPAIR(TTF_IDISHWND), //            0x0001
	ITC_NAMEPAIR(TTF_CENTERTIP), //           0x0002
	ITC_NAMEPAIR(TTF_RTLREADING), //          0x0004
	ITC_NAMEPAIR(TTF_SUBCLASS), //            0x0010
	ITC_NAMEPAIR(TTF_TRACK), //               0x0020
	ITC_NAMEPAIR(TTF_ABSOLUTE), //            0x0080
	ITC_NAMEPAIR(TTF_TRANSPARENT), //         0x0100
	ITC_NAMEPAIR(TTF_PARSELINKS), //          0x1000
	ITC_NAMEPAIR(TTF_DI_SETITEM), //          0x8000       // valid only on the TTN_NEEDTEXT callback
};
CInterpretConst TTF_xxx(_b2v_TTF_xxx, ITCF_HEX2B);

const Enum2Val_st _e2v_TTN_xxx[] =
{
	ITC_NAMEPAIR(TTN_NEEDTEXTA), //        (TTN_FIRST - 0)  // -520 (alias TTN_GETDISPINFOA)
	ITC_NAMEPAIR(TTN_NEEDTEXTW), //        (TTN_FIRST - 10) // -530 (alias TTN_GETDISPINFOW)
	ITC_NAMEPAIR(TTN_SHOW), //             (TTN_FIRST - 1)
	ITC_NAMEPAIR(TTN_POP), //              (TTN_FIRST - 2)
	ITC_NAMEPAIR(TTN_LINKCLICK), //        (TTN_FIRST - 3)
};
CInterpretConst TTN_xxx(_e2v_TTN_xxx, _e2v_NM_xxx_Generic, ITCF_SINT);

const Enum2Val_st _e2v_TTM_xxx[] = // tooltip window messages
{
	ITC_NAMEPAIR(TTM_ACTIVATE), //            (WM_USER + 1)
	ITC_NAMEPAIR(TTM_SETDELAYTIME), //        (WM_USER + 3)
	ITC_NAMEPAIR(TTM_ADDTOOLA), //            (WM_USER + 4)
	ITC_NAMEPAIR(TTM_ADDTOOLW), //            (WM_USER + 50)
	ITC_NAMEPAIR(TTM_DELTOOLA), //            (WM_USER + 5)
	ITC_NAMEPAIR(TTM_DELTOOLW), //            (WM_USER + 51)
	ITC_NAMEPAIR(TTM_NEWTOOLRECTA), //        (WM_USER + 6)
	ITC_NAMEPAIR(TTM_NEWTOOLRECTW), //        (WM_USER + 52)
	ITC_NAMEPAIR(TTM_RELAYEVENT), //          (WM_USER + 7) // Win7: wParam = GetMessageExtraInfo() when relaying WM_MOUSEMOVE
	ITC_NAMEPAIR(TTM_GETTOOLINFOA), //        (WM_USER + 8)
	ITC_NAMEPAIR(TTM_GETTOOLINFOW), //        (WM_USER + 53)
	ITC_NAMEPAIR(TTM_SETTOOLINFOA), //        (WM_USER + 9)
	ITC_NAMEPAIR(TTM_SETTOOLINFOW), //        (WM_USER + 54)
	ITC_NAMEPAIR(TTM_HITTESTA), //            (WM_USER +10)
	ITC_NAMEPAIR(TTM_HITTESTW), //            (WM_USER +55)
	ITC_NAMEPAIR(TTM_GETTEXTA), //            (WM_USER +11)
	ITC_NAMEPAIR(TTM_GETTEXTW), //            (WM_USER +56)
	ITC_NAMEPAIR(TTM_UPDATETIPTEXTA), //      (WM_USER +12)
	ITC_NAMEPAIR(TTM_UPDATETIPTEXTW), //      (WM_USER +57)
	ITC_NAMEPAIR(TTM_GETTOOLCOUNT), //        (WM_USER +13)
	ITC_NAMEPAIR(TTM_ENUMTOOLSA), //          (WM_USER +14)
	ITC_NAMEPAIR(TTM_ENUMTOOLSW), //          (WM_USER +58)
	ITC_NAMEPAIR(TTM_GETCURRENTTOOLA), //     (WM_USER + 15)
	ITC_NAMEPAIR(TTM_GETCURRENTTOOLW), //     (WM_USER + 59)
	ITC_NAMEPAIR(TTM_WINDOWFROMPOINT), //     (WM_USER + 16)
	ITC_NAMEPAIR(TTM_TRACKACTIVATE), //       (WM_USER + 17)  // wParam = TRUE/FALSE start end  lparam = LPTOOLINFO
	ITC_NAMEPAIR(TTM_TRACKPOSITION), //       (WM_USER + 18)  // lParam = dwPos
	ITC_NAMEPAIR(TTM_SETTIPBKCOLOR), //       (WM_USER + 19)
	ITC_NAMEPAIR(TTM_SETTIPTEXTCOLOR), //     (WM_USER + 20)
	ITC_NAMEPAIR(TTM_GETDELAYTIME), //        (WM_USER + 21)
	ITC_NAMEPAIR(TTM_GETTIPBKCOLOR), //       (WM_USER + 22)
	ITC_NAMEPAIR(TTM_GETTIPTEXTCOLOR), //     (WM_USER + 23)
	ITC_NAMEPAIR(TTM_SETMAXTIPWIDTH), //      (WM_USER + 24)
	ITC_NAMEPAIR(TTM_GETMAXTIPWIDTH), //      (WM_USER + 25)
	ITC_NAMEPAIR(TTM_SETMARGIN), //           (WM_USER + 26)  // lParam = lprc
	ITC_NAMEPAIR(TTM_GETMARGIN), //           (WM_USER + 27)  // lParam = lprc
	ITC_NAMEPAIR(TTM_POP), //                 (WM_USER + 28)
	ITC_NAMEPAIR(TTM_UPDATE), //              (WM_USER + 29)
	ITC_NAMEPAIR(TTM_GETBUBBLESIZE), //       (WM_USER + 30)
	ITC_NAMEPAIR(TTM_ADJUSTRECT), //          (WM_USER + 31)
	ITC_NAMEPAIR(TTM_SETTITLEA), //           (WM_USER + 32)  // wParam = TTI_*, lParam = char* szTitle
	ITC_NAMEPAIR(TTM_SETTITLEW), //           (WM_USER + 33)  // wParam = TTI_*, lParam = wchar* szTitle
	ITC_NAMEPAIR(TTM_POPUP), //               (WM_USER + 34)
	ITC_NAMEPAIR(TTM_GETTITLE), //            (WM_USER + 35) // wParam = 0, lParam = TTGETTITLE*
};
CInterpretConst TTM_xxx_WM_xxx(
	new Enum2Val_merge(
		_e2v_TTM_xxx, ARRAYSIZE(_e2v_TTM_xxx),
		_e2v_WM_xxx, N_e2v_WM_xxx,
		nullptr, 0)
	, ITCF_HEX1B);





const Enum2Val_st _e2v_CDDS_xxx[] = // custom-draw drawstage flags (NMCUSTOMDRAW)
{
	ITC_NAMEPAIR(CDDS_PREPAINT), //           0x00000001
	ITC_NAMEPAIR(CDDS_POSTPAINT), //          0x00000002
	ITC_NAMEPAIR(CDDS_PREERASE), //           0x00000003
	ITC_NAMEPAIR(CDDS_POSTERASE), //          0x00000004
	ITC_NAMEPAIR(CDDS_ITEM), //               0x00010000
	ITC_NAMEPAIR(CDDS_ITEMPREPAINT), //       (CDDS_ITEM | CDDS_PREPAINT)
	ITC_NAMEPAIR(CDDS_ITEMPOSTPAINT), //      (CDDS_ITEM | CDDS_POSTPAINT)
	ITC_NAMEPAIR(CDDS_ITEMPREERASE), //       (CDDS_ITEM | CDDS_PREERASE)
	ITC_NAMEPAIR(CDDS_ITEMPOSTERASE), //      (CDDS_ITEM | CDDS_POSTERASE)
	ITC_NAMEPAIR(CDDS_SUBITEM), //            0x00020000
};
CInterpretConst CDDS_xxx(_e2v_CDDS_xxx, ITCF_HEX1B);

const SingleBit2Val_st _b2v_CDIS_xxx[] = // custom-draw itemState flags (NMCUSTOMDRAW)
{
	ITC_NAMEPAIR(CDIS_SELECTED), //           0x0001
	ITC_NAMEPAIR(CDIS_GRAYED), //             0x0002
	ITC_NAMEPAIR(CDIS_DISABLED), //           0x0004
	ITC_NAMEPAIR(CDIS_CHECKED), //            0x0008
	ITC_NAMEPAIR(CDIS_FOCUS), //              0x0010
	ITC_NAMEPAIR(CDIS_DEFAULT), //            0x0020
	ITC_NAMEPAIR(CDIS_HOT), //                0x0040
	ITC_NAMEPAIR(CDIS_MARKED), //             0x0080
	ITC_NAMEPAIR(CDIS_INDETERMINATE), //      0x0100
	ITC_NAMEPAIR(CDIS_SHOWKEYBOARDCUES), //   0x0200
	ITC_NAMEPAIR(CDIS_NEARHOT), //            0x0400
	ITC_NAMEPAIR(CDIS_OTHERSIDEHOT), //       0x0800
	ITC_NAMEPAIR(CDIS_DROPHILITED), //        0x1000
};
CInterpretConst CDIS_xxx(_b2v_CDIS_xxx, ITCF_HEX2B);



}; // namespace itc
