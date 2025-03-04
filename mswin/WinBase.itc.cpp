#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "WinBase.itc.h"

namespace itc {

const SingleBit2Val_st _b2v_FilemapRight[] = 
{
	ITC_NAMEPAIR(FILE_MAP_COPY),  // 0x01
	ITC_NAMEPAIR(FILE_MAP_WRITE), // 0x02
	ITC_NAMEPAIR(FILE_MAP_READ),  // 0x04  
	ITC_NAMEPAIR(SECTION_MAP_EXECUTE), // 0x08
	ITC_NAMEPAIR(SECTION_EXTEND_SIZE), // 0x10
	ITC_NAMEPAIR(FILE_MAP_EXECUTE), // 0x20
};
CInterpretConst FilemapRights(ITCF_HEX1B,
	_b2v_FilemapRight, ARRAYSIZE(_b2v_FilemapRight),  
	_b2v_StandardRight, N_b2v_StandardRight,
	nullptr, 0);



} //namespace itc
