#define WIN32_LEAN_AND_MEAN
#include <windows.h> // for ARRAYSIZE

#include "..\itc\InterpretConst.h"

#include "democonst.h"

namespace itc {

const Enum2Val_st e2v_Demo1Enumgroup1[] =
{
	{ _T("G1_VAL0"), 0 },
	{ _T("G1_VAL1"), 1 },
	{ _T("G1_VAL2"), 2 },
	{ _T("G1_VAL3"), 3 },
};
const Enum2Val_st e2v_Demo1Enumgroup2[] =
{
	{ _T("G2_VAL0"), 0<<2 },
	{ _T("G2_VAL1"), 1<<2 },
	{ _T("G2_VAL2"), 2<<2 },
	{ nullptr, 3<<2 },
	{ _T("G2_VAL4"), 4<<2 },
	{ _T("G2_VAL5"), 5<<2 },
	{ _T("G2_VAL6"), 6<<2 },
//	{ _T("SEC2_VAL7"), 7<<2 },
};


const EnumGroup_st egs_Demo1[] =
{
	{ 0x3,    e2v_Demo1Enumgroup1, ARRAYSIZE(e2v_Demo1Enumgroup1) },
	{ 0x7<<2, e2v_Demo1Enumgroup2, ARRAYSIZE(e2v_Demo1Enumgroup2) },
};
//CInterpretConst itcDemo1(ITCF_HEX2B,
//	egs_Demo1, ARRAYSIZE(egs_Demo1),
//	nullptr, 0);
CInterpretConst Demo1(egs_Demo1);

////

const Enum2Val_st e2v_weekday[] =
{
	{_T("Sunday"), 0},
	{_T("Monday"), 1},
	{_T("Tuesday"), 2},
	{_T("Wednesday"), 3},
	{_T("Thursday"), 4},
	{_T("Friday"), 5},
	{_T("Saturday"), 6},
};
CInterpretConst Weekday(e2v_weekday);


} // namespace itc {
