#ifndef __itc__mmsystem_h_
#define __itc__mmsystem_h_
#define __itc__mmsystem_h_created_ 20260624
#define __itc__mmsystem_h_updated_ 20260624

#include <InterpretConst.h>

namespace itc {



extern const CInterpretConst& MCIERR_xxx();

/*
extern const SingleBit2Val_st _b2v_YYY[];
extern const int N_b2v_YYY;
extern const CInterpretConst& YYY();

*/

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
#if defined(mmsystem_itc_IMPL) || (defined CHHI_ALL_IMPL && !defined CHHI_ALL_IMPL_HIDE_mmsystem_itc) // [IMPL] begin
// [IMPL] //
// [IMPL] //
// Include system/OS headers here
#include <mmsystem.h>
// [IMPL] //
// [IMPL] //
namespace itc {

// More ctor reference: My evclip 20250411.v1

const Enum2Val_st _e2v_MCIERR_xxx[] =
{
	ITC_NAMEPAIR(MCIERR_INVALID_DEVICE_ID        ), // (MCIERR_BASE + 1)
	ITC_NAMEPAIR(MCIERR_UNRECOGNIZED_KEYWORD     ), // (MCIERR_BASE + 3)
	ITC_NAMEPAIR(MCIERR_UNRECOGNIZED_COMMAND     ), // (MCIERR_BASE + 5)
	ITC_NAMEPAIR(MCIERR_HARDWARE                 ), // (MCIERR_BASE + 6)
	ITC_NAMEPAIR(MCIERR_INVALID_DEVICE_NAME      ), // (MCIERR_BASE + 7)
	ITC_NAMEPAIR(MCIERR_OUT_OF_MEMORY            ), // (MCIERR_BASE + 8)
	ITC_NAMEPAIR(MCIERR_DEVICE_OPEN              ), // (MCIERR_BASE + 9)
	ITC_NAMEPAIR(MCIERR_CANNOT_LOAD_DRIVER       ), // (MCIERR_BASE + 10)
	ITC_NAMEPAIR(MCIERR_MISSING_COMMAND_STRING   ), // (MCIERR_BASE + 11)
	ITC_NAMEPAIR(MCIERR_PARAM_OVERFLOW           ), // (MCIERR_BASE + 12)
	ITC_NAMEPAIR(MCIERR_MISSING_STRING_ARGUMENT  ), // (MCIERR_BASE + 13)
	ITC_NAMEPAIR(MCIERR_BAD_INTEGER              ), // (MCIERR_BASE + 14)
	ITC_NAMEPAIR(MCIERR_PARSER_INTERNAL          ), // (MCIERR_BASE + 15)
	ITC_NAMEPAIR(MCIERR_DRIVER_INTERNAL          ), // (MCIERR_BASE + 16)
	ITC_NAMEPAIR(MCIERR_MISSING_PARAMETER        ), // (MCIERR_BASE + 17)
	ITC_NAMEPAIR(MCIERR_UNSUPPORTED_FUNCTION     ), // (MCIERR_BASE + 18)
	ITC_NAMEPAIR(MCIERR_FILE_NOT_FOUND           ), // (MCIERR_BASE + 19)
	ITC_NAMEPAIR(MCIERR_DEVICE_NOT_READY         ), // (MCIERR_BASE + 20)
	ITC_NAMEPAIR(MCIERR_INTERNAL                 ), // (MCIERR_BASE + 21)
	ITC_NAMEPAIR(MCIERR_DRIVER                   ), // (MCIERR_BASE + 22)
	ITC_NAMEPAIR(MCIERR_CANNOT_USE_ALL           ), // (MCIERR_BASE + 23)
	ITC_NAMEPAIR(MCIERR_MULTIPLE                 ), // (MCIERR_BASE + 24)
	ITC_NAMEPAIR(MCIERR_EXTENSION_NOT_FOUND      ), // (MCIERR_BASE + 25)
	ITC_NAMEPAIR(MCIERR_OUTOFRANGE               ), // (MCIERR_BASE + 26)
	ITC_NAMEPAIR(MCIERR_FLAGS_NOT_COMPATIBLE     ), // (MCIERR_BASE + 28)
	ITC_NAMEPAIR(MCIERR_FILE_NOT_SAVED           ), // (MCIERR_BASE + 30)
	ITC_NAMEPAIR(MCIERR_DEVICE_TYPE_REQUIRED     ), // (MCIERR_BASE + 31)
	ITC_NAMEPAIR(MCIERR_DEVICE_LOCKED            ), // (MCIERR_BASE + 32)
	ITC_NAMEPAIR(MCIERR_DUPLICATE_ALIAS          ), // (MCIERR_BASE + 33)
	ITC_NAMEPAIR(MCIERR_BAD_CONSTANT             ), // (MCIERR_BASE + 34)
	ITC_NAMEPAIR(MCIERR_MUST_USE_SHAREABLE       ), // (MCIERR_BASE + 35)
	ITC_NAMEPAIR(MCIERR_MISSING_DEVICE_NAME      ), // (MCIERR_BASE + 36)
	ITC_NAMEPAIR(MCIERR_BAD_TIME_FORMAT          ), // (MCIERR_BASE + 37)
	ITC_NAMEPAIR(MCIERR_NO_CLOSING_QUOTE         ), // (MCIERR_BASE + 38)
	ITC_NAMEPAIR(MCIERR_DUPLICATE_FLAGS          ), // (MCIERR_BASE + 39)
	ITC_NAMEPAIR(MCIERR_INVALID_FILE             ), // (MCIERR_BASE + 40)
	ITC_NAMEPAIR(MCIERR_NULL_PARAMETER_BLOCK     ), // (MCIERR_BASE + 41)
	ITC_NAMEPAIR(MCIERR_UNNAMED_RESOURCE         ), // (MCIERR_BASE + 42)
	ITC_NAMEPAIR(MCIERR_NEW_REQUIRES_ALIAS       ), // (MCIERR_BASE + 43)
	ITC_NAMEPAIR(MCIERR_NOTIFY_ON_AUTO_OPEN      ), // (MCIERR_BASE + 44)
	ITC_NAMEPAIR(MCIERR_NO_ELEMENT_ALLOWED       ), // (MCIERR_BASE + 45)
	ITC_NAMEPAIR(MCIERR_NONAPPLICABLE_FUNCTION   ), // (MCIERR_BASE + 46)
	ITC_NAMEPAIR(MCIERR_ILLEGAL_FOR_AUTO_OPEN    ), // (MCIERR_BASE + 47)
	ITC_NAMEPAIR(MCIERR_FILENAME_REQUIRED        ), // (MCIERR_BASE + 48)
	ITC_NAMEPAIR(MCIERR_EXTRA_CHARACTERS         ), // (MCIERR_BASE + 49)
	ITC_NAMEPAIR(MCIERR_DEVICE_NOT_INSTALLED     ), // (MCIERR_BASE + 50)
	ITC_NAMEPAIR(MCIERR_GET_CD                   ), // (MCIERR_BASE + 51)
	ITC_NAMEPAIR(MCIERR_SET_CD                   ), // (MCIERR_BASE + 52)
	ITC_NAMEPAIR(MCIERR_SET_DRIVE                ), // (MCIERR_BASE + 53)
	ITC_NAMEPAIR(MCIERR_DEVICE_LENGTH            ), // (MCIERR_BASE + 54)
	ITC_NAMEPAIR(MCIERR_DEVICE_ORD_LENGTH        ), // (MCIERR_BASE + 55)
	ITC_NAMEPAIR(MCIERR_NO_INTEGER               ), // (MCIERR_BASE + 56)
	
	ITC_NAMEPAIR(MCIERR_WAVE_OUTPUTSINUSE        ), // (MCIERR_BASE + 64)
	ITC_NAMEPAIR(MCIERR_WAVE_SETOUTPUTINUSE      ), // (MCIERR_BASE + 65)
	ITC_NAMEPAIR(MCIERR_WAVE_INPUTSINUSE         ), // (MCIERR_BASE + 66)
	ITC_NAMEPAIR(MCIERR_WAVE_SETINPUTINUSE       ), // (MCIERR_BASE + 67)
	ITC_NAMEPAIR(MCIERR_WAVE_OUTPUTUNSPECIFIED   ), // (MCIERR_BASE + 68)
	ITC_NAMEPAIR(MCIERR_WAVE_INPUTUNSPECIFIED    ), // (MCIERR_BASE + 69)
	ITC_NAMEPAIR(MCIERR_WAVE_OUTPUTSUNSUITABLE   ), // (MCIERR_BASE + 70)
	ITC_NAMEPAIR(MCIERR_WAVE_SETOUTPUTUNSUITABLE ), // (MCIERR_BASE + 71)
	ITC_NAMEPAIR(MCIERR_WAVE_INPUTSUNSUITABLE    ), // (MCIERR_BASE + 72)
	ITC_NAMEPAIR(MCIERR_WAVE_SETINPUTUNSUITABLE  ), // (MCIERR_BASE + 73)
	
	ITC_NAMEPAIR(MCIERR_SEQ_DIV_INCOMPATIBLE     ), // (MCIERR_BASE + 80)
	ITC_NAMEPAIR(MCIERR_SEQ_PORT_INUSE           ), // (MCIERR_BASE + 81)
	ITC_NAMEPAIR(MCIERR_SEQ_PORT_NONEXISTENT     ), // (MCIERR_BASE + 82)
	ITC_NAMEPAIR(MCIERR_SEQ_PORT_MAPNODEVICE     ), // (MCIERR_BASE + 83)
	ITC_NAMEPAIR(MCIERR_SEQ_PORT_MISCERROR       ), // (MCIERR_BASE + 84)
	ITC_NAMEPAIR(MCIERR_SEQ_TIMER                ), // (MCIERR_BASE + 85)
	ITC_NAMEPAIR(MCIERR_SEQ_PORTUNSPECIFIED      ), // (MCIERR_BASE + 86)
	ITC_NAMEPAIR(MCIERR_SEQ_NOMIDIPRESENT        ), // (MCIERR_BASE + 87)
	
	ITC_NAMEPAIR(MCIERR_NO_WINDOW                ), // (MCIERR_BASE + 90)
	ITC_NAMEPAIR(MCIERR_CREATEWINDOW             ), // (MCIERR_BASE + 91)
	ITC_NAMEPAIR(MCIERR_FILE_READ                ), // (MCIERR_BASE + 92)
	ITC_NAMEPAIR(MCIERR_FILE_WRITE               ), // (MCIERR_BASE + 93)
	
	ITC_NAMEPAIR(MCIERR_NO_IDENTITY              ), // (MCIERR_BASE + 94)
};
ITC_MAKE_OBJECT(MCIERR_xxx, _e2v_MCIERR_xxx, ITCF_SINT)




} // namespace itc
// [IMPL] //
// [IMPL] //
#endif // [IMPL] end


#endif // include once guard
