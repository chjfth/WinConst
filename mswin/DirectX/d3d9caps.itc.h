#ifndef __d3d9caps_h_20251208_
#define __d3d9caps_h_20251208_

#include <InterpretConst.h>

namespace itc {


extern CInterpretConst D3DVTXPCAPS;



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
#if defined(d3d9caps_IMPL) || (defined CHHI_ALL_IMPL && !defined CHHI_ALL_IMPL_HIDE_d3d9caps) // [IMPL]


/*

Reference: My evclip 20250411.v1

const Enum2Val_st _e2v_XXX[] =
{
    ITC_NAMEPAIR(NM_OUTOFMEMORY         ), // -1
    ITC_NAMEPAIR(NM_CLICK               ), // -2
    ITC_NAMEPAIR(NM_DBLCLK              ), // -3
};
CInterpretConst XXX(_e2v_XXX, ITCF_SINT);
*/

const SingleBit2Val_st _b2v_D3DVTXPCAPS[] =
{
	ITC_NAMEPAIR(D3DVTXPCAPS_TEXGEN              ), // 0x00000001L 
	ITC_NAMEPAIR(D3DVTXPCAPS_MATERIALSOURCE7     ), // 0x00000002L 
	ITC_NAMEPAIR(D3DVTXPCAPS_DIRECTIONALLIGHTS   ), // 0x00000008L 
	ITC_NAMEPAIR(D3DVTXPCAPS_POSITIONALLIGHTS    ), // 0x00000010L 
	ITC_NAMEPAIR(D3DVTXPCAPS_LOCALVIEWER         ), // 0x00000020L 
	ITC_NAMEPAIR(D3DVTXPCAPS_TWEENING            ), // 0x00000040L 
	ITC_NAMEPAIR(D3DVTXPCAPS_TEXGEN_SPHEREMAP    ), // 0x00000100L 
	ITC_NAMEPAIR(D3DVTXPCAPS_NO_TEXGEN_NONLOCALVIEWER), // 0x0200L 
};
const int N_b2v_D3DVTXPCAPS = ARRAYSIZE(_b2v_D3DVTXPCAPS);
CInterpretConst D3DVTXPCAPS(_b2v_D3DVTXPCAPS, ITCF_HEX2B);



#endif // [IMPL]


} // namespace itc

#endif // __d3d9caps_h_20251208_
