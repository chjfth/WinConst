#ifndef __directx_errors_h_20251208_
#define __directx_errors_h_20251208_

#include <InterpretConst.h>

namespace itc {


extern CInterpretConst DxErr;




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
#if defined(directx_errors_IMPL) || (defined CHHI_ALL_IMPL && !defined CHHI_ALL_IMPL_HIDE_directx_errors) // [IMPL]

#include <WinError.itc.h>
#include <DirectX\d3d9.itc.h>
#include <DirectX\d3dx9.itc.h>



CInterpretConst DxErr(
	new Enum2Val_merge(
		_e2v_D3DXERR, N_e2v_D3DXERR,
		_e2v_D3DERR,  N_e2v_D3DERR,
		_e2v_WinError, N_e2v_WinError,
		nullptr, 0) // this Enum2Val_merge object will not be deleted, by design
	, ITCF_HEX1B
	);





#endif // [IMPL]


} // namespace itc

#endif // __directx_errors_h_20251208_
