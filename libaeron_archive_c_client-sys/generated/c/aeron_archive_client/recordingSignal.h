/* Generated SBE (Simple Binary Encoding) message codec */

#ifndef _AERON_ARCHIVE_CLIENT_RECORDINGSIGNAL_H_
#define _AERON_ARCHIVE_CLIENT_RECORDINGSIGNAL_H_

#include <errno.h>
#if !defined(__STDC_LIMIT_MACROS)
#define __STDC_LIMIT_MACROS 1
#endif
#include <limits.h>
#define SBE_FLOAT_NAN NAN
#define SBE_DOUBLE_NAN NAN
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
#define SBE_ONE_DEF inline
#else
#define SBE_ONE_DEF static inline
#endif

/*
 * Define some byte ordering macros
 */
#if defined(WIN32) || defined(_WIN32)
    #define SBE_BIG_ENDIAN_ENCODE_16(v) _byteswap_ushort(v)
    #define SBE_BIG_ENDIAN_ENCODE_32(v) _byteswap_ulong(v)
    #define SBE_BIG_ENDIAN_ENCODE_64(v) _byteswap_uint64(v)
    #define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
    #define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
    #define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    #define SBE_BIG_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
    #define SBE_BIG_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
    #define SBE_BIG_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
    #define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
    #define SBE_BIG_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
    #define SBE_BIG_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
    #define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
    #define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
    #define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    #define SBE_LITTLE_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
    #define SBE_LITTLE_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
    #define SBE_LITTLE_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
    #define SBE_BIG_ENDIAN_ENCODE_16(v) (v)
    #define SBE_BIG_ENDIAN_ENCODE_32(v) (v)
    #define SBE_BIG_ENDIAN_ENCODE_64(v) (v)
#else
    #error "Byte Ordering of platform not determined. Set __BYTE_ORDER__ manually before including this file."
#endif

#if !defined(SBE_BOUNDS_CHECK_EXPECT)
#  if defined(SBE_NO_BOUNDS_CHECK)
#    define SBE_BOUNDS_CHECK_EXPECT(exp, c) (false)
#  elif defined(_MSC_VER)
#    define SBE_BOUNDS_CHECK_EXPECT(exp, c) (exp)
#  else 
#    define SBE_BOUNDS_CHECK_EXPECT(exp, c) (__builtin_expect(exp, c))
#  endif

#endif

#define SBE_NULLVALUE_INT8 INT8_MIN
#define SBE_NULLVALUE_INT16 INT16_MIN
#define SBE_NULLVALUE_INT32 INT32_MIN
#define SBE_NULLVALUE_INT64 INT64_MIN
#define SBE_NULLVALUE_UINT8 UINT8_MAX
#define SBE_NULLVALUE_UINT16 UINT16_MAX
#define SBE_NULLVALUE_UINT32 UINT32_MAX
#define SBE_NULLVALUE_UINT64 UINT64_MAX

#define E100 -50100 // E_BUF_SHORT
#define E103 -50103 // VAL_UNKNOWN_ENUM
#define E104 -50104 // I_OUT_RANGE_NUM
#define E105 -50105 // I_OUT_RANGE_NUM
#define E106 -50106 // I_OUT_RANGE_NUM
#define E107 -50107 // BUF_SHORT_FLYWEIGHT
#define E108 -50108 // BUF_SHORT_NXT_GRP_IND
#define E109 -50109 // STR_TOO_LONG_FOR_LEN_TYP
#define E110 -50110 // CNT_OUT_RANGE

#ifndef SBE_STRERROR_DEFINED
#define SBE_STRERROR_DEFINED
SBE_ONE_DEF const char *sbe_strerror(const int errnum)
{
    switch (errnum)
    {
        case E100:
            return "buffer too short";
        case E103:
            return "unknown value for enum";
        case E104:
            return "index out of range";
        case E105:
            return "index out of range";
        case E106:
            return "length too large";
        case E107:
            return "buffer too short for flyweight";
        case E108:
            return "buffer too short to support next group index";
        case E109:
            return "std::string too long for length type";
        case E110:
            return "count outside of allowed range";
        default:
            return "unknown error";
    }
}
#endif

enum aeron_archive_client_recordingSignal
{
    aeron_archive_client_recordingSignal_START = INT32_C(0),
    aeron_archive_client_recordingSignal_STOP = INT32_C(1),
    aeron_archive_client_recordingSignal_EXTEND = INT32_C(2),
    aeron_archive_client_recordingSignal_REPLICATE = INT32_C(3),
    aeron_archive_client_recordingSignal_MERGE = INT32_C(4),
    aeron_archive_client_recordingSignal_SYNC = INT32_C(5),
    aeron_archive_client_recordingSignal_DELETE = INT32_C(6),
    aeron_archive_client_recordingSignal_REPLICATE_END = INT32_C(7),
    aeron_archive_client_recordingSignal_NULL_VALUE = INT32_MIN
};

SBE_ONE_DEF bool aeron_archive_client_recordingSignal_get(
    const int32_t value,
    enum aeron_archive_client_recordingSignal *const out)
{
    switch (value)
    {
        case INT32_C(0):
             *out = aeron_archive_client_recordingSignal_START;
             return true;
        case INT32_C(1):
             *out = aeron_archive_client_recordingSignal_STOP;
             return true;
        case INT32_C(2):
             *out = aeron_archive_client_recordingSignal_EXTEND;
             return true;
        case INT32_C(3):
             *out = aeron_archive_client_recordingSignal_REPLICATE;
             return true;
        case INT32_C(4):
             *out = aeron_archive_client_recordingSignal_MERGE;
             return true;
        case INT32_C(5):
             *out = aeron_archive_client_recordingSignal_SYNC;
             return true;
        case INT32_C(6):
             *out = aeron_archive_client_recordingSignal_DELETE;
             return true;
        case INT32_C(7):
             *out = aeron_archive_client_recordingSignal_REPLICATE_END;
             return true;
        case INT32_MIN:
             *out = aeron_archive_client_recordingSignal_NULL_VALUE;
             return true;
    }

    errno = E103;
    return false;
}

#endif
