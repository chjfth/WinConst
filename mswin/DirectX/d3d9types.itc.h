#ifndef __d3d9types_h_20251208_
#define __d3d9types_h_20251208_

#include <InterpretConst.h>

namespace itc {


extern CInterpretConst D3DFMT;
extern CInterpretConst D3DTEXTUREADDRESS;
extern CInterpretConst D3DTEXTUREFILTERTYPE;
extern CInterpretConst D3DZBUFFERTYPE;

extern CInterpretConst D3DFILLMODE;
extern CInterpretConst D3DSHADEMODE;

extern CInterpretConst D3DBLEND;

extern CInterpretConst D3DCULL;

extern CInterpretConst D3DCMPFUNC;

extern CInterpretConst D3DFOGMODE;

extern CInterpretConst D3DSTENCILOP;

extern CInterpretConst D3DMATERIALCOLORSOURCE;

extern CInterpretConst D3DVERTEXBLENDFLAGS;

extern CInterpretConst D3DPATCHEDGESTYLE;

extern CInterpretConst D3DBLENDOP;

extern CInterpretConst D3DDEGREETYPE;

}

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
#if defined(d3d9types_IMPL) || (defined CHHI_ALL_IMPL && !defined CHHI_ALL_IMPL_HIDE_d3d9types) // [IMPL]


namespace itc {

// More ctor reference: My evclip 20250411.v1

const Enum2Val_st _e2v_D3DFMT[] =
{
	ITC_NAMEPAIR(D3DFMT_UNKNOWN              ), // =  0,

	ITC_NAMEPAIR(D3DFMT_R8G8B8               ), // = 20,
	ITC_NAMEPAIR(D3DFMT_A8R8G8B8             ), // = 21,
	ITC_NAMEPAIR(D3DFMT_X8R8G8B8             ), // = 22,
	ITC_NAMEPAIR(D3DFMT_R5G6B5               ), // = 23,
	ITC_NAMEPAIR(D3DFMT_X1R5G5B5             ), // = 24,
	ITC_NAMEPAIR(D3DFMT_A1R5G5B5             ), // = 25,
	ITC_NAMEPAIR(D3DFMT_A4R4G4B4             ), // = 26,
	ITC_NAMEPAIR(D3DFMT_R3G3B2               ), // = 27,
	ITC_NAMEPAIR(D3DFMT_A8                   ), // = 28,
	ITC_NAMEPAIR(D3DFMT_A8R3G3B2             ), // = 29,
	ITC_NAMEPAIR(D3DFMT_X4R4G4B4             ), // = 30,
	ITC_NAMEPAIR(D3DFMT_A2B10G10R10          ), // = 31,
	ITC_NAMEPAIR(D3DFMT_A8B8G8R8             ), // = 32,
	ITC_NAMEPAIR(D3DFMT_X8B8G8R8             ), // = 33,
	ITC_NAMEPAIR(D3DFMT_G16R16               ), // = 34,
	ITC_NAMEPAIR(D3DFMT_A2R10G10B10          ), // = 35,
	ITC_NAMEPAIR(D3DFMT_A16B16G16R16         ), // = 36,

	ITC_NAMEPAIR(D3DFMT_A8P8                 ), // = 40,
	ITC_NAMEPAIR(D3DFMT_P8                   ), // = 41,

	ITC_NAMEPAIR(D3DFMT_L8                   ), // = 50,
	ITC_NAMEPAIR(D3DFMT_A8L8                 ), // = 51,
	ITC_NAMEPAIR(D3DFMT_A4L4                 ), // = 52,

	ITC_NAMEPAIR(D3DFMT_V8U8                 ), // = 60,
	ITC_NAMEPAIR(D3DFMT_L6V5U5               ), // = 61,
	ITC_NAMEPAIR(D3DFMT_X8L8V8U8             ), // = 62,
	ITC_NAMEPAIR(D3DFMT_Q8W8V8U8             ), // = 63,
	ITC_NAMEPAIR(D3DFMT_V16U16               ), // = 64,
	ITC_NAMEPAIR(D3DFMT_A2W10V10U10          ), // = 67,

	ITC_NAMEPAIR(D3DFMT_UYVY                 ), // = MAKEFOURCC('U', 'Y', 'V', 'Y'),
	ITC_NAMEPAIR(D3DFMT_R8G8_B8G8            ), // = MAKEFOURCC('R', 'G', 'B', 'G'),
	ITC_NAMEPAIR(D3DFMT_YUY2                 ), // = MAKEFOURCC('Y', 'U', 'Y', '2'),
	ITC_NAMEPAIR(D3DFMT_G8R8_G8B8            ), // = MAKEFOURCC('G', 'R', 'G', 'B'),
	ITC_NAMEPAIR(D3DFMT_DXT1                 ), // = MAKEFOURCC('D', 'X', 'T', '1'),
	ITC_NAMEPAIR(D3DFMT_DXT2                 ), // = MAKEFOURCC('D', 'X', 'T', '2'),
	ITC_NAMEPAIR(D3DFMT_DXT3                 ), // = MAKEFOURCC('D', 'X', 'T', '3'),
	ITC_NAMEPAIR(D3DFMT_DXT4                 ), // = MAKEFOURCC('D', 'X', 'T', '4'),
	ITC_NAMEPAIR(D3DFMT_DXT5                 ), // = MAKEFOURCC('D', 'X', 'T', '5'),

	ITC_NAMEPAIR(D3DFMT_D16_LOCKABLE         ), // = 70,
	ITC_NAMEPAIR(D3DFMT_D32                  ), // = 71,
	ITC_NAMEPAIR(D3DFMT_D15S1                ), // = 73,
	ITC_NAMEPAIR(D3DFMT_D24S8                ), // = 75,
	ITC_NAMEPAIR(D3DFMT_D24X8                ), // = 77,
	ITC_NAMEPAIR(D3DFMT_D24X4S4              ), // = 79,
	ITC_NAMEPAIR(D3DFMT_D16                  ), // = 80,

	ITC_NAMEPAIR(D3DFMT_D32F_LOCKABLE        ), // = 82,
	ITC_NAMEPAIR(D3DFMT_D24FS8               ), // = 83,

	ITC_NAMEPAIR(D3DFMT_L16                  ), // = 81,

#if D3D_SDK_VERSION>=32
	ITC_NAMEPAIR(D3DFMT_D32_LOCKABLE         ), // = 84,
	ITC_NAMEPAIR(D3DFMT_S8_LOCKABLE          ), // = 85,
#endif

	ITC_NAMEPAIR(D3DFMT_VERTEXDATA           ), // =100,
	ITC_NAMEPAIR(D3DFMT_INDEX16              ), // =101,
	ITC_NAMEPAIR(D3DFMT_INDEX32              ), // =102,

	ITC_NAMEPAIR(D3DFMT_Q16W16V16U16         ), // =110,

	ITC_NAMEPAIR(D3DFMT_MULTI2_ARGB8         ), // = MAKEFOURCC('M','E','T','1'),
	
	ITC_NAMEPAIR(D3DFMT_R16F                 ), // = 111,
	ITC_NAMEPAIR(D3DFMT_G16R16F              ), // = 112,
	ITC_NAMEPAIR(D3DFMT_A16B16G16R16F        ), // = 113,

	ITC_NAMEPAIR(D3DFMT_R32F                 ), // = 114,
	ITC_NAMEPAIR(D3DFMT_G32R32F              ), // = 115,
	ITC_NAMEPAIR(D3DFMT_A32B32G32R32F        ), // = 116,

	ITC_NAMEPAIR(D3DFMT_CxV8U8               ), // = 117,

#if D3D_SDK_VERSION>=32
	ITC_NAMEPAIR(D3DFMT_A1                   ), // = 118,
	ITC_NAMEPAIR(D3DFMT_A2B10G10R10_XR_BIAS  ), // = 119,
	ITC_NAMEPAIR(D3DFMT_BINARYBUFFER         ), // = 199,
#endif
};
CInterpretConst D3DFMT(_e2v_D3DFMT, ITCF_SINT);


const Enum2Val_st _e2v_D3DTEXTUREADDRESS[] =
{
	ITC_NAMEPAIR(D3DTADDRESS_WRAP            ), //= 1,
	ITC_NAMEPAIR(D3DTADDRESS_MIRROR          ), //= 2,
	ITC_NAMEPAIR(D3DTADDRESS_CLAMP           ), //= 3,
	ITC_NAMEPAIR(D3DTADDRESS_BORDER          ), //= 4,
	ITC_NAMEPAIR(D3DTADDRESS_MIRRORONCE      ), //= 5,
};
CInterpretConst D3DTEXTUREADDRESS(_e2v_D3DTEXTUREADDRESS, ITCF_SINT);


const Enum2Val_st _e2v_D3DTEXTUREFILTERTYPE[] =
{
	ITC_NAMEPAIR(D3DTEXF_NONE           ), // = 0,
	ITC_NAMEPAIR(D3DTEXF_POINT          ), // = 1,
	ITC_NAMEPAIR(D3DTEXF_LINEAR         ), // = 2,
	ITC_NAMEPAIR(D3DTEXF_ANISOTROPIC    ), // = 3,
	ITC_NAMEPAIR(D3DTEXF_PYRAMIDALQUAD  ), // = 6,
	ITC_NAMEPAIR(D3DTEXF_GAUSSIANQUAD   ), // = 7,
#if !defined(D3D_DISABLE_9EX)			
	ITC_NAMEPAIR(D3DTEXF_CONVOLUTIONMONO), // = 8,
#endif									
};
CInterpretConst D3DTEXTUREFILTERTYPE(_e2v_D3DTEXTUREFILTERTYPE, ITCF_SINT);


const Enum2Val_st _e2v_D3DZBUFFERTYPE[] =
{
	ITC_NAMEPAIR(D3DZB_FALSE                ), // = 0,
	ITC_NAMEPAIR(D3DZB_TRUE                 ), // = 1,
	ITC_NAMEPAIR(D3DZB_USEW                 ), // = 2,
};
CInterpretConst D3DZBUFFERTYPE(_e2v_D3DZBUFFERTYPE, ITCF_SINT);


const Enum2Val_st _e2v_D3DFILLMODE[] =
{
	ITC_NAMEPAIR(D3DFILL_POINT              ), // = 1,
	ITC_NAMEPAIR(D3DFILL_WIREFRAME          ), // = 2,
	ITC_NAMEPAIR(D3DFILL_SOLID              ), // = 3,
};
CInterpretConst D3DFILLMODE(_e2v_D3DFILLMODE, ITCF_SINT);


const Enum2Val_st _e2v_D3DSHADEMODE[] =
{
	ITC_NAMEPAIR(D3DSHADE_FLAT              ), // = 1,
	ITC_NAMEPAIR(D3DSHADE_GOURAUD           ), // = 2,
	ITC_NAMEPAIR(D3DSHADE_PHONG             ), // = 3,
};
CInterpretConst D3DSHADEMODE(_e2v_D3DSHADEMODE, ITCF_SINT);


const Enum2Val_st _e2v_D3DBLEND[] =
{
	ITC_NAMEPAIR(D3DBLEND_ZERO              ), // = 1,
	ITC_NAMEPAIR(D3DBLEND_ONE               ), // = 2,
	ITC_NAMEPAIR(D3DBLEND_SRCCOLOR          ), // = 3,
	ITC_NAMEPAIR(D3DBLEND_INVSRCCOLOR       ), // = 4,
	ITC_NAMEPAIR(D3DBLEND_SRCALPHA          ), // = 5,
	ITC_NAMEPAIR(D3DBLEND_INVSRCALPHA       ), // = 6,
	ITC_NAMEPAIR(D3DBLEND_DESTALPHA         ), // = 7,
	ITC_NAMEPAIR(D3DBLEND_INVDESTALPHA      ), // = 8,
	ITC_NAMEPAIR(D3DBLEND_DESTCOLOR         ), // = 9,
	ITC_NAMEPAIR(D3DBLEND_INVDESTCOLOR      ), // = 10,
	ITC_NAMEPAIR(D3DBLEND_SRCALPHASAT       ), // = 11,
	ITC_NAMEPAIR(D3DBLEND_BOTHSRCALPHA      ), // = 12,
	ITC_NAMEPAIR(D3DBLEND_BOTHINVSRCALPHA   ), // = 13,
	ITC_NAMEPAIR(D3DBLEND_BLENDFACTOR       ), // = 14,
	ITC_NAMEPAIR(D3DBLEND_INVBLENDFACTOR    ), // = 15,
#if !defined(D3D_DISABLE_9EX)
	ITC_NAMEPAIR(D3DBLEND_SRCCOLOR2         ), // = 16,
	ITC_NAMEPAIR(D3DBLEND_INVSRCCOLOR2      ), // = 17,
#endif
};
CInterpretConst D3DBLEND(_e2v_D3DBLEND, ITCF_SINT);


const Enum2Val_st _e2v_D3DCMPFUNC[] =
{
	ITC_NAMEPAIR(D3DCMP_NEVER             ), //   = 1,
	ITC_NAMEPAIR(D3DCMP_LESS              ), //   = 2,
	ITC_NAMEPAIR(D3DCMP_EQUAL             ), //   = 3,
	ITC_NAMEPAIR(D3DCMP_LESSEQUAL         ), //   = 4,
	ITC_NAMEPAIR(D3DCMP_GREATER           ), //   = 5,
	ITC_NAMEPAIR(D3DCMP_NOTEQUAL          ), //   = 6,
	ITC_NAMEPAIR(D3DCMP_GREATEREQUAL      ), //   = 7,
	ITC_NAMEPAIR(D3DCMP_ALWAYS            ), //   = 8,

};
CInterpretConst D3DCMPFUNC(_e2v_D3DCMPFUNC, ITCF_SINT);


const Enum2Val_st _e2v_D3DCULL[] =
{
	ITC_NAMEPAIR(D3DCULL_NONE        ), // = 1,
	ITC_NAMEPAIR(D3DCULL_CW          ), // = 2,
	ITC_NAMEPAIR(D3DCULL_CCW         ), // = 3,
};
CInterpretConst D3DCULL(_e2v_D3DCULL, ITCF_SINT);


const Enum2Val_st _e2v_D3DFOGMODE[] =
{
	ITC_NAMEPAIR(D3DFOG_NONE      ), //   = 0,
	ITC_NAMEPAIR(D3DFOG_EXP       ), //   = 1,
	ITC_NAMEPAIR(D3DFOG_EXP2      ), //   = 2,
	ITC_NAMEPAIR(D3DFOG_LINEAR    ), //   = 3,
};
CInterpretConst D3DFOGMODE(_e2v_D3DFOGMODE, ITCF_SINT);


const Enum2Val_st _e2v_D3DSTENCILOP[] =
{
	ITC_NAMEPAIR(D3DSTENCILOP_KEEP       ), //  = 1,
	ITC_NAMEPAIR(D3DSTENCILOP_ZERO       ), //  = 2,
	ITC_NAMEPAIR(D3DSTENCILOP_REPLACE    ), //  = 3,
	ITC_NAMEPAIR(D3DSTENCILOP_INCRSAT    ), //  = 4,
	ITC_NAMEPAIR(D3DSTENCILOP_DECRSAT    ), //  = 5,
	ITC_NAMEPAIR(D3DSTENCILOP_INVERT     ), //  = 6,
	ITC_NAMEPAIR(D3DSTENCILOP_INCR       ), //  = 7,
	ITC_NAMEPAIR(D3DSTENCILOP_DECR       ), //  = 8,
};
CInterpretConst D3DSTENCILOP(_e2v_D3DSTENCILOP, ITCF_SINT);


const Enum2Val_st _e2v_D3DMATERIALCOLORSOURCE[] =
{
	ITC_NAMEPAIR(D3DMCS_MATERIAL   ), //  = 0,
	ITC_NAMEPAIR(D3DMCS_COLOR1     ), //  = 1,
	ITC_NAMEPAIR(D3DMCS_COLOR2     ), //  = 2,
};
CInterpretConst D3DMATERIALCOLORSOURCE(_e2v_D3DMATERIALCOLORSOURCE, ITCF_SINT);


const Enum2Val_st _e2v_D3DVERTEXBLENDFLAGS[] =
{
	ITC_NAMEPAIR(D3DVBF_DISABLE  ), // = 0,
	ITC_NAMEPAIR(D3DVBF_1WEIGHTS ), // = 1,
	ITC_NAMEPAIR(D3DVBF_2WEIGHTS ), // = 2,
	ITC_NAMEPAIR(D3DVBF_3WEIGHTS ), // = 3,
	ITC_NAMEPAIR(D3DVBF_TWEENING ), // = 255,
	ITC_NAMEPAIR(D3DVBF_0WEIGHTS ), // = 256
};
CInterpretConst D3DVERTEXBLENDFLAGS(_e2v_D3DVERTEXBLENDFLAGS, ITCF_SINT);


const Enum2Val_st _e2v_D3DPATCHEDGESTYLE[] =
{
	ITC_NAMEPAIR(D3DPATCHEDGE_DISCRETE    ), // = 0,
	ITC_NAMEPAIR(D3DPATCHEDGE_CONTINUOUS  ), // = 1,
};
CInterpretConst D3DPATCHEDGESTYLE(_e2v_D3DPATCHEDGESTYLE, ITCF_SINT);


const Enum2Val_st _e2v_D3DBLENDOP[] =
{
	ITC_NAMEPAIR(D3DBLENDOP_ADD        ), //  = 1,
	ITC_NAMEPAIR(D3DBLENDOP_SUBTRACT   ), //  = 2,
	ITC_NAMEPAIR(D3DBLENDOP_REVSUBTRACT), //  = 3,
	ITC_NAMEPAIR(D3DBLENDOP_MIN        ), //  = 4,
	ITC_NAMEPAIR(D3DBLENDOP_MAX        ), //  = 5,
};
CInterpretConst D3DBLENDOP(_e2v_D3DBLENDOP, ITCF_SINT);


const Enum2Val_st _e2v_D3DDEGREETYPE[] =
{
	ITC_NAMEPAIR(D3DDEGREE_LINEAR    ), // = 1,
	ITC_NAMEPAIR(D3DDEGREE_QUADRATIC ), // = 2,
	ITC_NAMEPAIR(D3DDEGREE_CUBIC     ), // = 3,
	ITC_NAMEPAIR(D3DDEGREE_QUINTIC   ), // = 5,
};
CInterpretConst D3DDEGREETYPE(_e2v_D3DDEGREETYPE, ITCF_SINT);

/*
const SingleBit2Val_st _b2v_YYY[] =
{
    ITC_NAMEPAIR(DELETE),       //   (0x00010000L)
    ITC_NAMEPAIR(READ_CONTROL), //   (0x00020000L)
    ITC_NAMEPAIR(WRITE_DAC),    //   (0x00040000L)
    ITC_NAMEPAIR(WRITE_OWNER),  //   (0x00080000L)
    ITC_NAMEPAIR(SYNCHRONIZE),  //   (0x00100000L)
};
const int N_b2v_YYY = ARRAYSIZE(_b2v_YYY);
CInterpretConst YYY(_b2v_YYY, ITCF_HEX4B);

*/


} // namespace itc

#endif // [IMPL]


#endif // __d3d9types_h_20251208_
