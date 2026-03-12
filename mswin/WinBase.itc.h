#ifndef __CHHI__WinBase_h_20260312_
#define __CHHI__WinBase_h_20260312_

#include <InterpretConst.h>

namespace itc {

extern const CInterpretConst FilemapRights;

extern const CInterpretConst dwCreationDisposition;

extern const CInterpretConst FILE_FLAG_xxx;
extern const CInterpretConst dwFlagsAndAttributes;

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
#if defined(WinBase_itc_IMPL) || (defined CHHI_ALL_IMPL && !defined CHHI_ALL_IMPL_HIDE_WinBase_itc) // [IMPL] begin
// [IMPL] //
// [IMPL] //
// Include system/OS headers here
#include <mswin/WinNT.itc.h>
// [IMPL] //
// [IMPL] //
namespace itc {

// More ctor reference: My evclip 20250411.v1

const SingleBit2Val_st _b2v_FilemapRight[] = 
{
	ITC_NAMEPAIR(FILE_MAP_COPY),  // 0x01
	ITC_NAMEPAIR(FILE_MAP_WRITE), // 0x02
	ITC_NAMEPAIR(FILE_MAP_READ),  // 0x04  
	ITC_NAMEPAIR(SECTION_MAP_EXECUTE), // 0x08
	ITC_NAMEPAIR(SECTION_EXTEND_SIZE), // 0x10
	ITC_NAMEPAIR(FILE_MAP_EXECUTE), // 0x20
};
const CInterpretConst FilemapRights(ITCF_HEX1B,
	_b2v_FilemapRight, ARRAYSIZE(_b2v_FilemapRight),  
	_b2v_StandardRight, N_b2v_StandardRight,
	nullptr, 0);


const Enum2Val_st _e2v_dwCreationDisposition[] =
{
	ITC_NAMEPAIR(CREATE_NEW), //          1
	ITC_NAMEPAIR(CREATE_ALWAYS), //       2
	ITC_NAMEPAIR(OPEN_EXISTING), //       3
	ITC_NAMEPAIR(OPEN_ALWAYS), //         4
	ITC_NAMEPAIR(TRUNCATE_EXISTING), //   5
};
const CInterpretConst dwCreationDisposition(_e2v_dwCreationDisposition, ITCF_UINT);


const SingleBit2Val_st _b2v_FILE_FLAG_xxx[] =
{
	ITC_NAMEPAIR(FILE_FLAG_WRITE_THROUGH), //         0x80000000
	ITC_NAMEPAIR(FILE_FLAG_OVERLAPPED), //            0x40000000
	ITC_NAMEPAIR(FILE_FLAG_NO_BUFFERING), //          0x20000000
	ITC_NAMEPAIR(FILE_FLAG_RANDOM_ACCESS), //         0x10000000
	ITC_NAMEPAIR(FILE_FLAG_SEQUENTIAL_SCAN), //       0x08000000
	ITC_NAMEPAIR(FILE_FLAG_DELETE_ON_CLOSE), //       0x04000000
	ITC_NAMEPAIR(FILE_FLAG_BACKUP_SEMANTICS), //      0x02000000
	ITC_NAMEPAIR(FILE_FLAG_POSIX_SEMANTICS), //       0x01000000
	ITC_NAMEPAIR(FILE_FLAG_OPEN_REPARSE_POINT), //    0x00200000
	ITC_NAMEPAIR(FILE_FLAG_OPEN_NO_RECALL), //        0x00100000 sad, conflicts with SECURITY_SQOS_PRESENT
	ITC_NAMEPAIR(FILE_FLAG_FIRST_PIPE_INSTANCE), //   0x00080000 sad, conflicts with SECURITY_EFFECTIVE_ONLY
};
const CInterpretConst FILE_FLAG_xxx(_b2v_FILE_FLAG_xxx, ITCF_HEX4B);


const CInterpretConst dwFlagsAndAttributes(ITCF_HEX4B,
	_b2v_FILE_ATTRIBUTE_xxx, N_b2v_FILE_ATTRIBUTE_xxx, // need WinNT.itc.h
	_b2v_FILE_FLAG_xxx, ARRAYSIZE(_b2v_FILE_FLAG_xxx), 
	nullptr, 0);


} // namespace itc
// [IMPL] //
// [IMPL] //
#endif // [IMPL] end


#endif // CHHI__WinBase_h_20260312_
