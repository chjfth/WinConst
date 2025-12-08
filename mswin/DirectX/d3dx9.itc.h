#ifndef __d3dx9_h_20251208_
#define __d3dx9_h_20251208_

#include <InterpretConst.h>

namespace itc {


extern CInterpretConst D3DXERR;
extern const Enum2Val_st _e2v_D3DXERR[];
extern const int        N_e2v_D3DXERR;



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
#if defined(d3dx9_IMPL) || (defined CHHI_ALL_IMPL && !defined CHHI_ALL_IMPL_HIDE_d3dx9) // [IMPL]

#include <d3dx9.h>
#include "d3d9.itc.h"

const Enum2Val_st _e2v_D3DXERR[] =
{
	ITC_NAMEPAIR(D3DXERR_CANNOTMODIFYINDEXBUFFER     ), // MAKE_DDHRESULT(2900),
	ITC_NAMEPAIR(D3DXERR_INVALIDMESH                 ), // MAKE_DDHRESULT(2901),
	ITC_NAMEPAIR(D3DXERR_CANNOTATTRSORT              ), // MAKE_DDHRESULT(2902),
	ITC_NAMEPAIR(D3DXERR_SKINNINGNOTSUPPORTED        ), // MAKE_DDHRESULT(2903),
	ITC_NAMEPAIR(D3DXERR_TOOMANYINFLUENCES           ), // MAKE_DDHRESULT(2904),
	ITC_NAMEPAIR(D3DXERR_INVALIDDATA                 ), // MAKE_DDHRESULT(2905),
	ITC_NAMEPAIR(D3DXERR_LOADEDMESHASNODATA          ), // MAKE_DDHRESULT(2906),
	ITC_NAMEPAIR(D3DXERR_DUPLICATENAMEDFRAGMENT      ), // MAKE_DDHRESULT(2907),
#if D3D_SDK_VERSION_lowbyte >= 32
	ITC_NAMEPAIR(D3DXERR_CANNOTREMOVELASTITEM		 ), // MAKE_DDHRESULT(2908), // since DXSDK Oct-2004, not in DXSDK9
#endif
};
CInterpretConst D3DXERR(_e2v_D3DXERR, ITCF_HEX4B);
const int N_e2v_D3DXERR = ARRAYSIZE(_e2v_D3DXERR);






#endif // [IMPL]


} // namespace itc

#endif // __d3dx9_h_20251208_
