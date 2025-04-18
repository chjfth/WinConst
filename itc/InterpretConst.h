#ifndef __InterpretConst_h_20250417_
#define __InterpretConst_h_20250417_

#include <tchar.h> // for TCHAR & _T
#include <stdio.h>
#include <stdarg.h>


namespace itc {


typedef unsigned long CONSTVAL_t;

struct Enum2Val_st // ok
{
	const TCHAR *EnumName;
	CONSTVAL_t ConstVal;
};

struct SingleBit2Val_st // oldname Bitfield2Val_st
{
	const TCHAR *BitfieldName;
	CONSTVAL_t ConstVal;
};

struct EnumGroup_st
{
	CONSTVAL_t GroupMask;
	const Enum2Val_st *arEnum2Val;
	int nEnum2Val; // element count of arEnum2Val[]
	
	// const TCHAR *zvName; // const-name for zero-value, points to arEnum2Val[x].BitfieldName . (unimplemented yet)
};

typedef EnumGroup_st ItcGroup_st;
// -- CInterpretConst internally sees a single-bit-group as a special case
//    of an enum-group(GroupMask has only one bit set), so create an alias name
//    `ItcGroup_st` for internal use.

struct Error // As C++ exception type
{
	Error(const TCHAR* msg)
	{
		this->msg = msg;
	}

	const TCHAR* msg;
};


struct DisplayTrait_st
{
	// How to display this segment.

	unsigned segname : 1;	// display segment name itself.
	// -- This is effective only if ItcSeg_st.segname exists.

	unsigned possign : 1;	// for valname, show positive sign('+')

	unsigned negsign : 1;	// want negative valname
	// -- By default, if a bit has value 0, its corresponding valname is not displayed.
	//    But if show_negsign==1, the negative-valname will be displayed. Two cases exit:
	//    (1) If neg_valname exists, that neg_valname is displayed.
	//    (2) No neg_valname exists, '-' prefixed valname is displayed, like "-WS_CHILD".

	unsigned negsign_smallcase : 1; // will show "-ws_child" instead of "-WS_CHILD"
	// -- This is effective only if negsign presentation is effective.

	unsigned numdec : 1; // besides valname, show valnum in decimal
	unsigned numhex : 1; // besides valname, show valnum in hex (0x...)

	unsigned rela_numdec : 1; // show relative valnum in decimal
	unsigned rela_numhex : 1; // show relative valnum in hex (0x...)
};

const DisplayTrait_st disp_default0 = {};
	
struct ItcSeg_st
{
	// This describes an Itc-Segment, a base class.

	const TCHAR* segname;	// (optional) segment name
	CONSTVAL_t segmask;		// bitmask of this segment

	DisplayTrait_st disp;

	ItcSeg_st(const TCHAR* i_segname, CONSTVAL_t i_segmask, DisplayTrait_st i_disp)
	{
		segname = i_segname;
		segmask = i_segmask;
		disp = i_disp;
	}
};

struct ZeroneSeg_st : public ItcSeg_st
{
	// 'Zerone' implies: No matter how many bits this segment involves,
	// it contains only two meaningful values, all bits are zero, or all bits are one.
	// For example, a ZeroneSeg_st has .segmask=0x3, then 0x0 and 0x3 are its
	// only two valid values, 0x1 and 0x2 are invalid.
	
	const TCHAR* pos_valname; // (optional) positive value-name, default to segname
	const TCHAR* neg_valname; // (optional) negative value-name, default to "-pos_valname".

	ZeroneSeg_st(const TCHAR* i_segname, CONSTVAL_t i_segmask, DisplayTrait_st i_disp,
		const TCHAR *i_pos_valname=nullptr, const TCHAR* i_neg_valname=nullptr)
		:
		ItcSeg_st(i_segname, i_segmask, i_disp),
		pos_valname(i_pos_valname),
		neg_valname(i_neg_valname)
	{
		// TODO: check null name case
	}
};

/*
struct EnumSeg_st : public ItcSeg_st
{
	// This is segment that can hold multiple values(normally >2).
	// The Itc-designer enumerates(vt. Enum) meaningful values
	// inside this segment.

	int nEnum2Val;
	const Enum2Val_st* arEnum2Val;

	// [2025-01-25] 
	// TODO: warning C4510: 'itc::EnumSeg_st' : default constructor could not be generated
};
*/

	
enum DisplayFormat_et
{
	DF_ValueOnly = 0,
	DF_NameOnly = 1,
	DF_NameAndValue = 2, // name(value)
	DF_ValueAndName = 3, // value(name)

	DF_NVAuto = 8 // If enum-trait, value(name); if bitfield-trait, name(valud) 
};

class String // this is inside itc namespace
{
public:
	String(int need_chars)
	{
#ifdef ITC_DEBUG_PRINT
		_tprintf(_T("[%p]CItcString() ctor: %d\n"), this, need_chars);
#endif // ITC_DEBUG_PRINT

		m_chars = need_chars;
		m_str = new TCHAR[m_chars];
	}

	String(const String &itc)
	{
#ifdef ITC_DEBUG_PRINT
		_tprintf(_T("[%p]CItcString() ctor= %s\n"), this, itc.m_str);
#endif // ITC_DEBUG_PRINT

		m_chars = itc.m_chars;
		m_str = new TCHAR[m_chars];
		_sntprintf_s(m_str, m_chars, _TRUNCATE, _T("%s"), itc.m_str);
	}

	~String()
	{
#ifdef ITC_DEBUG_PRINT
		_tprintf(_T("[%p]CItcString() dtor: %s\n"), this, m_str);
#endif // ITC_DEBUG_PRINT
		delete m_str;
		m_str = 0;
		m_chars = 0;
	}

	TCHAR *get(){ return m_str; }

	void put(const TCHAR *pstr)
	{
		if(m_str)
		{
			_sntprintf_s(m_str, m_chars, _TRUNCATE, _T("%s"), pstr);
		}
	}

	int bufsize(){ return m_chars; }

	operator TCHAR *(){ return m_str; }

private:
	TCHAR *m_str;
	int m_chars;
};


class Enum2Val_merge
{
	// Use this class to merge two or more existing Enum2Val_st arrays into 
	// a single Enum2Val_st array, so that the single array can be used to 
	// construct a CInterpretConst object.

	// Extra memory is allocated to store the new contiguous Enum2Val_st array.

public:
	Enum2Val_merge(const Enum2Val_st *arEnum2Val, int nEnum2Val, 
		... // more [arEnum2Val, nEnum2Val] pairs, end with [nullptr, 0]
		);

	~Enum2Val_merge() {
		delete mar_enum2val;
		mar_enum2val = nullptr;
		m_count = 0;
	}

	const Enum2Val_st* get_array() const { 
		return mar_enum2val;
	}
	
	int count() const {
		return m_count;
	}

private:
	Enum2Val_st *mar_enum2val;
	int m_count;
};


class CInterpretConst
{
public:
	virtual ~CInterpretConst();

	CInterpretConst(const Enum2Val_st *arEnum2Val, int nEnum2Val, const TCHAR *valfmt=nullptr)
	{
		_ctor(arEnum2Val, nEnum2Val, valfmt);
	}

	template<size_t eles>
	CInterpretConst(const Enum2Val_st (&ar)[eles], const TCHAR *valfmt=nullptr)
	{
		_ctor(ar, eles, valfmt);
	}

	template<size_t eles1, size_t eles2>
	CInterpretConst(
		const Enum2Val_st (&ar1)[eles1], 
		const Enum2Val_st (&ar2)[eles2],
		const TCHAR *valfmt=nullptr)
	{
		// to-test
		Enum2Val_merge *ar_e2vmerge = new Enum2Val_merge(
			ar1, eles1,  ar2, eles2,
			nullptr, 0) // this Enum2Val_merge object will not be deleted, by design
		_ctor(ar_e2vmerge->get_array(), ar_e2vmerge->count(), valfmt);
	}

	CInterpretConst(const Enum2Val_merge *ar_e2vmerge, const TCHAR *valfmt=nullptr)
	{
		_ctor(ar_e2vmerge->get_array(), ar_e2vmerge->count(), valfmt);
	}

	//

	CInterpretConst(const SingleBit2Val_st *arSingleBit2Val, int nSingleBit2Val, const TCHAR *valfmt=nullptr)
	{
		_ctor(arSingleBit2Val, nSingleBit2Val, valfmt);
	}

	template<size_t eles>
	CInterpretConst(const SingleBit2Val_st (&ar)[eles], const TCHAR *valfmt=nullptr)
	{
		_ctor(ar, eles, valfmt);
	}

	template<size_t eles1, size_t eles2>
	CInterpretConst(
		const SingleBit2Val_st (&ar1)[eles1],
		const SingleBit2Val_st (&ar2)[eles2],
		const TCHAR *valfmt=nullptr)
	{
		// A facility ctor that combines two SingleBit2Val_st-s
		// Example: winnt.itc: FileRights, DirectoryRights

		_ctor(valfmt, 
			nullptr, 0, // no Enum2Val_st
			ar1, eles1,  ar2, eles2,
			nullptr, 0);
	}

	template<size_t eles1, size_t eles2, size_t eles3>
	CInterpretConst(
		const SingleBit2Val_st (&ar1)[eles1],
		const SingleBit2Val_st (&ar2)[eles2],
		const SingleBit2Val_st (&ar3)[eles3],
		const TCHAR *valfmt=nullptr)
	{
		// A facility ctor that combines three SingleBit2Val_st-s

		_ctor(valfmt, 
			nullptr, 0, // no Enum2Val_st
			ar1, eles1,  ar2, eles2, ar3, eles3,
			nullptr, 0);
	}

	//

	CInterpretConst(const EnumGroup_st *arGroups, int nGroups, const TCHAR *valfmt=nullptr)
	{
		_ctor(arGroups, nGroups, valfmt);
	}

	template<size_t eles>
	CInterpretConst(const EnumGroup_st (&ar)[eles], const TCHAR *valfmt=nullptr)
	{
		_ctor(ar, eles, valfmt);
	}

	//

	CInterpretConst(const TCHAR *valfmt,
		const SingleBit2Val_st *arSinglebit2Val, int nSinglebit2Val,
		... // more [arSinglebit2Val, nSinglebit2Val] pairs, end with [nullptr, 0]
		) // VK0
	{
		va_list args;
		va_start(args, valfmt);
		_ctor(valfmt, nullptr, 0, args); // call to the {most generic initor}
		va_end(args);
	}

	CInterpretConst(const TCHAR *valfmt,
		const EnumGroup_st *arGroups, int nGroups, 
		const SingleBit2Val_st *arSinglebit2Val, int nSinglebit2Val,
		... // more [arSinglebit2Val, nSinglebit2Val] pairs, end with [nullptr, 0]
		) // VK1
	{
		va_list args;
		va_start(args, nGroups); // yes, start from `nGroups`
		_ctor(valfmt, arGroups, nGroups, args);
		va_end(args);
	}

	CInterpretConst(const TCHAR *valfmt,
		const Enum2Val_st *arEnum2Val, int nEnum2Val, 
		const SingleBit2Val_st *arSinglebit2Val, int nSinglebit2Val,
		... // more [arSinglebit2Val, nSinglebit2Val] pairs, end with [nullptr, 0]
		) // VK2
	{
		// This is a simplified version of VK1.

		// auto-calculate the mask for Enum2Val-s.
		CONSTVAL_t enum_mask = 0;
		for(int i=0; i<nEnum2Val; i++)
		{
			enum_mask |= arEnum2Val[i].ConstVal;
		}

		EnumGroup_st eg = { enum_mask, arEnum2Val, nEnum2Val };
		// -- this object will get a copy inside the following _ctor()

		va_list args;
		va_start(args, nEnum2Val); // yes, start from `nGroups`

		_ctor(valfmt, &eg, 1, args);

		va_end(args);
	}

	////

	const TCHAR *Interpret_i1(CONSTVAL_t val, DisplayFormat_et dispfmt,
		TCHAR *buf, int bufsize) const;

	String Interpret(CONSTVAL_t val, DisplayFormat_et dispfmt=DF_NameOnly) const;

	bool SetValFmt(const TCHAR *fmt);

	TCHAR *DumpText(TCHAR buf[], int nbufchars, int *pReqBufsize=nullptr);

	template<size_t eles>
	TCHAR *DumpText(TCHAR (&ar)[eles])
	{
		return DumpText(ar, eles, nullptr);
	}


private:
	enum { 
		WholeDisplayMaxChars = 2000,
		OneDisplayMaxChars = 100,
		FmtSpecMaxChars = 10,
	};

private:
	void _ctor(const Enum2Val_st *arEnum2Val, int nEnum2Val, 
		const TCHAR *valfmt);

	void _ctor(const SingleBit2Val_st *arBitfield2Val, int nBitfield2Val, 
		const TCHAR *valfmt);

	void _ctor(const EnumGroup_st *arGroups, int nGroups, 
		const TCHAR *valfmt);

	void _ctor(const TCHAR *valfmt,
		const EnumGroup_st *arGroups, int nGroups, 
		va_list args  // [arSinglebit2Val, nSinglebit2Val] pairs, end with [nullptr, nullptr]
		); // {most generic initor}, combine two sets of input

	void _ctor(const TCHAR *valfmt,
		const EnumGroup_st *arGroups, int nGroups, 
		const SingleBit2Val_st *arSinglebit2Val, int nSinglebit2Val,
		... // more [arSinglebit2Val, nSinglebit2Val] pairs, end with [nullptr, 0]
		)
	{
		va_list args;
		va_start(args, nGroups); // yes, start from `nGroups`
		_ctor(valfmt, arGroups, nGroups, args);
		va_end(args);
	}

private:
	void _reset(const TCHAR *valfmt);
	bool is_enum_ctor() const { return m_arGroups==&m_EnumC2V; };
	static bool is_unique_mask(CONSTVAL_t oldmasks, CONSTVAL_t newmask);
	bool ensure_unique_masks();

	const TCHAR *displayfmt() const;

	TCHAR *FormatOneDisplay(const TCHAR *szVal, CONSTVAL_t val, DisplayFormat_et dispfmt,
		TCHAR obuf[], int obufsize) const;

private:
	EnumGroup_st m_EnumC2V; // in the case of a single group
	bool m_dtor_delete_groups;

	const TCHAR *m_valfmt; 
	// -- format string when showing value, "%d", "%X", "0x%04X" etc

private:
	ItcGroup_st *m_arGroups;
	int m_nGroups;

	void *ptr_unused1, *ptr_unused2, *ptr_unused3, *ptr_unused4;
};


#define ITC_NAMEPAIR(macroname) { _T( #macroname ) , (CONSTVAL_t)macroname }

#define ITCS(val, itcobj) (itcobj).Interpret((itc::CONSTVAL_t)(val), itc::DF_NameOnly).get()
// -- the "return" of ITCS() macro can be passed as snprintf's variadic params
// Note: ITCS() cannot be used in __try{} block, otherwise we'll get Compiler Error C2712.

#define ITCSnv(val, itcobj) (itcobj).Interpret((itc::CONSTVAL_t)(val), itc::DF_NameAndValue).get()

#define ITCSvn(val, itcobj) (itcobj).Interpret((itc::CONSTVAL_t)(val), itc::DF_ValueAndName).get()

#define ITCSv(val, itcobj) (itcobj).Interpret((itc::CONSTVAL_t)(val), itc::DF_NVAuto).get()


#define ITCF_UINT _T("%u") // unsigned int (default)
#define ITCF_SINT _T("%d") // signed int

#define ITCF_HEX1B _T("0x%02X")
#define ITCF_HEX2B _T("0x%04X")
#define ITCF_HEX4B _T("0x%08X")


/*
class CEngine
{
public:
	CEngine();
	virtual ~CEngine();

	void InitZerones(int nZerones, const ZeroneSeg_st *arZerones);

	void InitEnums(int nEnumSegs, const EnumSeg_st *arEnumSegs);
	
private:

	int m_nzerones;
	ZeroneSeg_st* mar_zerones;

	int m_nenum_segs;
	EnumSeg_st* mar_enum_segs;
};
*/

	
} // namespace itc

#endif
