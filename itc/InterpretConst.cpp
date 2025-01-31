#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include "InterpretConst.h"

namespace itc {


Enum2Val_merge::Enum2Val_merge(const Enum2Val_st *arEnum2Val, int nEnum2Val, 
	... // more [arEnum2Val, nEnum2Val] pairs, end with [nullptr, 0]
	)
{
	va_list args;

	// First pass, scan through input params to get total Enum2Val count.
	// Note: This is not count of [arEnum2Val, nEnum2Val] pairs, but total of Enum2Val_st objects.

	int count = nEnum2Val;

	va_start(args, nEnum2Val);

	for(;;)
	{
		const Enum2Val_st *p = va_arg(args, const Enum2Val_st *);
		int n = va_arg(args, int);

		if(!p)
			break;

		count += n;
	}

	va_end(args);
	
	m_count = count;
	mar_enum2val = new Enum2Val_st[count];

	// Second pass, copy the Enum2Val_st content into the new array.

	va_start(args, nEnum2Val);

	const Enum2Val_st *ar_now = arEnum2Val;
	int n = nEnum2Val;
	int idx = 0;

	for(;;)
	{
		for(int i=0; i<n; i++)
		{
			mar_enum2val[idx+i].ConstVal = ar_now[i].ConstVal;
			mar_enum2val[idx+i].EnumName = ar_now[i].EnumName;
		}

		idx += n;

		ar_now = va_arg(args, const Enum2Val_st *);
		n = va_arg(args, int);

		if(!ar_now)
			break;
	}

	va_end(args);
}


void CInterpretConst::_reset(const TCHAR *valfmt)
{
	m_EnumC2V.GroupMask=0; 
	m_EnumC2V.arEnum2Val=nullptr; 
	m_EnumC2V.nEnum2Val=0; 

	m_dtor_delete_groups = false;

	SetValFmt( valfmt );

	m_arGroups = nullptr;
	m_nGroups = 0;
}

bool CInterpretConst::SetValFmt(const TCHAR *fmt)
{
	// fmt example: "%d", "%X", "0x%02X", "0x%04X"

	if(fmt==nullptr || fmt[0]=='\0')
	{
		m_valfmt = nullptr;
		return true;
	}

	// simple fmt format checking:
	// try to format a value 0x3F, check whether we get "3F", "3f" or "63" in output string. 

	bool is_correct_valfmt = true;

	if(fmt)
	{
		TCHAR tbuf[OneDisplayMaxChars] = {};
		_sntprintf_s(tbuf, _TRUNCATE, fmt, 0x3F);

		if(_tcsstr(tbuf, _T("3F"))==nullptr 
			&& _tcsstr(tbuf, _T("3f"))==nullptr
			&& _tcsstr(tbuf, _T("63"))==nullptr
			)
			is_correct_valfmt = false;

		assert(is_correct_valfmt==true);
	}

	m_valfmt = is_correct_valfmt ? fmt : nullptr; // can be nullptr, means default

	return is_correct_valfmt;
}

CInterpretConst::~CInterpretConst()
{
	if(m_dtor_delete_groups)
		delete []m_arGroups;
}

void CInterpretConst::_ctor(const Enum2Val_st *arEnum2Val, int nEnum2Val,
	const TCHAR *valfmt)
{
	_reset(valfmt);

	m_EnumC2V.GroupMask = 0xFFFFffff;
	m_EnumC2V.arEnum2Val = arEnum2Val;
	m_EnumC2V.nEnum2Val = nEnum2Val;

	m_arGroups = &m_EnumC2V;
	m_nGroups = 1;

	ensure_unique_masks();
}

void CInterpretConst::_ctor(const SingleBit2Val_st *arBitfield2Val, int nBitfield2Val,
	const TCHAR *valfmt)
{
	_reset(valfmt);

	m_arGroups = new ItcGroup_st[nBitfield2Val];
	if(!m_arGroups)
		return;

	m_nGroups = nBitfield2Val;

	int i;
	for(i=0; i<nBitfield2Val; i++)
	{
		assert(arBitfield2Val[i].ConstVal != 0); // a common input mistake

		m_arGroups[i].GroupMask = arBitfield2Val[i].ConstVal;
		m_arGroups[i].arEnum2Val = reinterpret_cast<const Enum2Val_st*>(arBitfield2Val+i);
		m_arGroups[i].nEnum2Val = 1;
	}

	m_dtor_delete_groups = true;

	ensure_unique_masks();
}

void CInterpretConst::_ctor(const ItcGroup_st *arGroups, int nGroups,
	const TCHAR *valfmt)
{
	_reset(valfmt);

	m_arGroups = const_cast<ItcGroup_st*>(arGroups);
	m_nGroups = nGroups;

	ensure_unique_masks();
}

#ifdef _MSC_VER
#ifndef va_copy
// VC2010 lacks va_copy, so manual supply it
#define va_copy(destination, source) ((destination) = (source))
#endif
#endif 

void CInterpretConst::_ctor(const TCHAR *valfmt,
	const EnumGroup_st *arGroups, int nGroups, 
	va_list args // [arSinglebit2Val, nSinglebit2Val] pairs, end with [nullptr, nullptr]
	)
{
	_reset(valfmt);

	va_list args_copy;
	va_copy(args_copy, args); // save a copy for 2nd-iteration


	//// 1st iteration ////

	// check quantity of input bitfields chunks >>>

	int nBitfieldsChunk = 0; // debug
	int nBitfieldsAll = 0;

	for(; ; nBitfieldsChunk++)
	{
		const SingleBit2Val_st *p = va_arg(args, const SingleBit2Val_st *);
		int n = va_arg(args, int);
		
		if(!p)
			break;

		nBitfieldsAll += n;
	}

	// check quantity of input bitfields chunks <<< 
	// (Result in nBitfieldsAll.)

	m_nGroups = nGroups + nBitfieldsAll;

	m_arGroups = new ItcGroup_st[m_nGroups];
	if(!m_arGroups)
		return;

	//// 2nd iteration ////

	// Copy input Enum-groups to internal buffer.

	for(int i=0; i<nGroups; i++)
	{
		m_arGroups[i].GroupMask = arGroups[i].GroupMask;
		m_arGroups[i].arEnum2Val = arGroups[i].arEnum2Val;
		m_arGroups[i].nEnum2Val  = arGroups[i].nEnum2Val;
	}

	// Copy input bitfields to internal buffer.

	int bfall_verify = 0;

	int advGroup = nGroups;
	
	for(; ;)
	{
		assert(bfall_verify<=nBitfieldsAll);

		const SingleBit2Val_st *pBF = va_arg(args_copy, const SingleBit2Val_st *);
		int nBF = va_arg(args_copy, int);

		if(!pBF)
			break;

		for(int j=0; j<nBF; j++)
		{
			m_arGroups[advGroup+j].GroupMask = pBF[j].ConstVal;
			m_arGroups[advGroup+j].arEnum2Val = reinterpret_cast<const Enum2Val_st*>(pBF+j);
			m_arGroups[advGroup+j].nEnum2Val  = 1;
		}

		advGroup   += nBF;
		bfall_verify += nBF;
	}

	assert(bfall_verify==nBitfieldsAll);

	va_end(args_copy);

	m_dtor_delete_groups = true;

	ensure_unique_masks();
}

bool CInterpretConst::is_unique_mask(CONSTVAL_t oldmasks, CONSTVAL_t newmask)
{
	// oldmasks and newmask must NOT have overlapped bits set.

	if( (oldmasks^newmask) == (oldmasks|newmask) )
		return true;
	else
		return false;
}

bool CInterpretConst::ensure_unique_masks()
{
	CONSTVAL_t accum_masks = 0;
	int sec;
	for(sec=0; sec<m_nGroups; sec++)
	{
		assert(m_arGroups[sec].GroupMask != 0);

		bool ok_unique_mask	= is_unique_mask(accum_masks, m_arGroups[sec].GroupMask);
		assert(ok_unique_mask);

		if(!ok_unique_mask)
			return false;

		accum_masks |= m_arGroups[sec].GroupMask;
	}

	return true;
}

const TCHAR* CInterpretConst::displayfmt()
{
	const TCHAR *pfmt = m_valfmt;

	if(!pfmt)
	{
		pfmt = is_enum_ctor() ? _T("%u") : _T("0x%X");
	}

	return pfmt; // always points to an persistent string
}

TCHAR* CInterpretConst::FormatOneDisplay(
	const TCHAR *szVal, CONSTVAL_t val, DisplayFormat_et dispfmt, 
	TCHAR obuf[], int obufsize)
{
	_sntprintf_s(obuf, obufsize, _TRUNCATE, _T("%s"), szVal);
	int len1 = (int)_tcslen(obuf);

	assert(len1<obufsize);

	if(dispfmt==DF_NameAndValue)
	{
		// Add brackets to value, let "0x3F" shown as "(0x3F)"
		TCHAR _valfmt_[FmtSpecMaxChars+2] = {};
		_sntprintf_s(_valfmt_, _TRUNCATE, _T("(%s)"), displayfmt());

		_sntprintf_s(obuf+len1, obufsize-len1, _TRUNCATE, _valfmt_, val);
	}

	return obuf;
}

const TCHAR *CInterpretConst::Interpret(
	CONSTVAL_t input_val, DisplayFormat_et dispfmt,
	TCHAR *buf, int bufsize)
{
	if(bufsize<=0)
		return NULL;

	buf[0] = 0;

	CONSTVAL_t remain_val = input_val;

	int sec = 0;
	for(sec=0; sec<m_nGroups; sec++)
	{
		CONSTVAL_t secval = input_val & m_arGroups[sec].GroupMask;

		auto c2v = m_arGroups[sec].arEnum2Val;
		int i;
		for(i=0; i<m_arGroups[sec].nEnum2Val; i++)
		{
			if(c2v[i].ConstVal==secval)
			{
				if(c2v[i].EnumName)
				{
					TCHAR szbuf[OneDisplayMaxChars] = {};
					_sntprintf_s(buf, bufsize, _TRUNCATE, _T("%s%s|"), 
						buf, 
						FormatOneDisplay(c2v[i].EnumName, c2v[i].ConstVal, 
						dispfmt, szbuf, ARRAYSIZE(szbuf))
						);
				}

				break;
			}
		}

		if(i==m_arGroups[sec].nEnum2Val)
		{
			// No designated name exists, we consider it an unrecognized value from
			// ITC interpreter's knowledge, so should present its HEXRR instead of mute on it.

			if( secval!=0 || i>1 )
			{
				TCHAR szfmt_concat[20] = {};
				_sntprintf_s(szfmt_concat, _TRUNCATE, _T("%%s%s"), displayfmt());
				
				_sntprintf_s(buf, bufsize, _TRUNCATE, szfmt_concat, buf, secval);
			}
			else
			{
				// It's a single-bit group and secval==0, 
				// this 0-value is of course not considered unrecognized, so mute it here. 

				assert(secval==0);
			}
		}

		remain_val &= ~m_arGroups[sec].GroupMask;
	}

	if(remain_val)
	{
		// present unrecognized value to user
		_sntprintf_s(buf, bufsize, _TRUNCATE, _T("%s0x%X|"), buf, remain_val);
	}

	// Remove trailing '|'
	int slen = (int)_tcslen(buf);
	if(slen>0 && buf[slen-1]=='|')
		buf[--slen] = '\0';

	// If output string empty, fill a '0'.
	if(buf[0]=='\0' && bufsize>=2)
		buf[0] = '0', buf[1] = 0;

	return buf;
}

String CInterpretConst::Interpret(
	CONSTVAL_t input_val, DisplayFormat_et dispfmt)
{
	String itcs(WholeDisplayMaxChars);
	Interpret(input_val, dispfmt, itcs.get(), itcs.bufsize());
	return itcs;
}


} // namespace itc
