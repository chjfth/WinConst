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


const SingleBit2Val_st b2v_StandardRight[] =
{
	ITC_NAMEPAIR(DELETE),       //   (0x00010000L)
	ITC_NAMEPAIR(READ_CONTROL), //   (0x00020000L)
	ITC_NAMEPAIR(WRITE_DAC),    //   (0x00040000L)
	ITC_NAMEPAIR(WRITE_OWNER),  //   (0x00080000L)
	ITC_NAMEPAIR(SYNCHRONIZE),  //   (0x00100000L)
};

const SingleBit2Val_st b2v_FileRight[] =
{
	ITC_NAMEPAIR(FILE_READ_DATA),   // 0x0001
	ITC_NAMEPAIR(FILE_WRITE_DATA),  // 0x0002
	ITC_NAMEPAIR(FILE_APPEND_DATA), // 0x0004
	ITC_NAMEPAIR(FILE_READ_EA),     // 0x0008
	ITC_NAMEPAIR(FILE_WRITE_EA),    // 0x0010
	ITC_NAMEPAIR(FILE_EXECUTE),     // 0x0020
	ITC_NAMEPAIR(FILE_READ_ATTRIBUTES), // 0x0080
	ITC_NAMEPAIR(FILE_WRITE_ATTRIBUTES),// 0X0100
};

const SingleBit2Val_st b2v_DirectoryRight[] =
{
	ITC_NAMEPAIR(FILE_LIST_DIRECTORY), // 0x0001
	ITC_NAMEPAIR(FILE_ADD_FILE),       // 0x0002
	ITC_NAMEPAIR(FILE_ADD_SUBDIRECTORY), // 0x0004
	ITC_NAMEPAIR(FILE_READ_EA),     // 0x0008
	ITC_NAMEPAIR(FILE_WRITE_EA),    // 0x0010
	ITC_NAMEPAIR(FILE_TRAVERSE),    // 0x0020
	ITC_NAMEPAIR(FILE_DELETE_CHILD),// 0x0040
	ITC_NAMEPAIR(FILE_READ_ATTRIBUTES), // 0x0080
	ITC_NAMEPAIR(FILE_WRITE_ATTRIBUTES),// 0X0100
};

CInterpretConst FileRights(b2v_FileRight, b2v_StandardRight, ITCF_HEX1B);
CInterpretConst DirectoryRights(b2v_DirectoryRight, b2v_StandardRight, ITCF_HEX1B);


} //namespace itc
