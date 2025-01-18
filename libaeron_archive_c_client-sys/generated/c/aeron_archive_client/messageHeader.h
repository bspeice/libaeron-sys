/* Generated SBE (Simple Binary Encoding) message codec */

#ifndef _AERON_ARCHIVE_CLIENT_MESSAGEHEADER_H_
#define _AERON_ARCHIVE_CLIENT_MESSAGEHEADER_H_

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

struct aeron_archive_client_messageHeader
{
    char *buffer;
    uint64_t buffer_length;
    uint64_t offset;
    uint64_t acting_version;
};

enum aeron_archive_client_messageHeader_meta_attribute
{
    aeron_archive_client_messageHeader_meta_attribute_EPOCH,
    aeron_archive_client_messageHeader_meta_attribute_TIME_UNIT,
    aeron_archive_client_messageHeader_meta_attribute_SEMANTIC_TYPE,
    aeron_archive_client_messageHeader_meta_attribute_PRESENCE
};

union aeron_archive_client_messageHeader_float_as_uint
{
    float fp_value;
    uint32_t uint_value;
};

union aeron_archive_client_messageHeader_double_as_uint
{
    double fp_value;
    uint64_t uint_value;
};

struct aeron_archive_client_messageHeader_string_view
{
    const char* data;
    size_t length;
};

SBE_ONE_DEF struct aeron_archive_client_messageHeader *aeron_archive_client_messageHeader_reset(
    struct aeron_archive_client_messageHeader *const codec,
    char *buffer,
    const uint64_t offset,
    const uint64_t buffer_length,
    const uint64_t acting_version)
{
    if (SBE_BOUNDS_CHECK_EXPECT(((offset + 8) > buffer_length), false))
    {
        errno = E107;
        return NULL;
    }
    codec->buffer = buffer;
    codec->buffer_length = buffer_length;
    codec->offset = offset;
    codec->acting_version = acting_version;

    return codec;
}

SBE_ONE_DEF struct aeron_archive_client_messageHeader *aeron_archive_client_messageHeader_wrap(
    struct aeron_archive_client_messageHeader *const codec,
    char *buffer,
    const uint64_t offset,
    const uint64_t acting_version,
    const uint64_t buffer_length)
{
    return aeron_archive_client_messageHeader_reset(codec, buffer, offset, buffer_length, acting_version);
}

SBE_ONE_DEF uint64_t aeron_archive_client_messageHeader_encoded_length(void)
{
    return 8;
}

SBE_ONE_DEF uint64_t aeron_archive_client_messageHeader_offset(
    const struct aeron_archive_client_messageHeader *const codec)
{
    return codec->offset;
}

SBE_ONE_DEF const char *aeron_archive_client_messageHeader_buffer(
    const struct aeron_archive_client_messageHeader *const codec)
{
    return codec->buffer;
}

SBE_ONE_DEF char *aeron_archive_client_messageHeader_mut_buffer(
    struct aeron_archive_client_messageHeader *const codec)
{
    return codec->buffer;
}

SBE_ONE_DEF uint64_t aeron_archive_client_messageHeader_buffer_length(
    const struct aeron_archive_client_messageHeader *const codec)
{
    return codec->buffer_length;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_sbe_schema_id(void)
{
    return (uint16_t)101;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_sbe_schema_version(void)
{
    return (uint16_t)10;
}

SBE_ONE_DEF const char *aeron_archive_client_messageHeader_blockLength_meta_attribute(
    const enum aeron_archive_client_messageHeader_meta_attribute attribute)
{
    switch (attribute)
    {
        case aeron_archive_client_messageHeader_meta_attribute_EPOCH: return "";
        case aeron_archive_client_messageHeader_meta_attribute_TIME_UNIT: return "";
        case aeron_archive_client_messageHeader_meta_attribute_SEMANTIC_TYPE: return "";
        case aeron_archive_client_messageHeader_meta_attribute_PRESENCE: return "required";
    }

    return "";
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_blockLength_id(void)
{
    return -1;
}

SBE_ONE_DEF uint64_t aeron_archive_client_messageHeader_blockLength_since_version(void)
{
    return 0;
}

SBE_ONE_DEF bool aeron_archive_client_messageHeader_blockLength_in_acting_version(
    const struct aeron_archive_client_messageHeader *const codec)
{
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
    return codec->acting_version >= aeron_archive_client_messageHeader_blockLength_since_version();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
}

SBE_ONE_DEF size_t aeron_archive_client_messageHeader_blockLength_encoding_offset(void)
{
    return 0;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_blockLength_null_value(void)
{
    return SBE_NULLVALUE_UINT16;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_blockLength_min_value(void)
{
    return (uint16_t)0;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_blockLength_max_value(void)
{
    return (uint16_t)65534;
}

SBE_ONE_DEF size_t aeron_archive_client_messageHeader_blockLength_encoding_length(void)
{
    return 2;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_blockLength(
    const struct aeron_archive_client_messageHeader *const codec)
{
    uint16_t val;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(&val, codec->buffer + codec->offset + 0, sizeof(uint16_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return SBE_LITTLE_ENDIAN_ENCODE_16(val);
}

SBE_ONE_DEF struct aeron_archive_client_messageHeader *aeron_archive_client_messageHeader_set_blockLength(
    struct aeron_archive_client_messageHeader *const codec,
    const uint16_t value)
{
    uint16_t val = SBE_LITTLE_ENDIAN_ENCODE_16(value);
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(codec->buffer + codec->offset + 0, &val, sizeof(uint16_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return codec;
}

SBE_ONE_DEF const char *aeron_archive_client_messageHeader_templateId_meta_attribute(
    const enum aeron_archive_client_messageHeader_meta_attribute attribute)
{
    switch (attribute)
    {
        case aeron_archive_client_messageHeader_meta_attribute_EPOCH: return "";
        case aeron_archive_client_messageHeader_meta_attribute_TIME_UNIT: return "";
        case aeron_archive_client_messageHeader_meta_attribute_SEMANTIC_TYPE: return "";
        case aeron_archive_client_messageHeader_meta_attribute_PRESENCE: return "required";
    }

    return "";
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_templateId_id(void)
{
    return -1;
}

SBE_ONE_DEF uint64_t aeron_archive_client_messageHeader_templateId_since_version(void)
{
    return 0;
}

SBE_ONE_DEF bool aeron_archive_client_messageHeader_templateId_in_acting_version(
    const struct aeron_archive_client_messageHeader *const codec)
{
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
    return codec->acting_version >= aeron_archive_client_messageHeader_templateId_since_version();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
}

SBE_ONE_DEF size_t aeron_archive_client_messageHeader_templateId_encoding_offset(void)
{
    return 2;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_templateId_null_value(void)
{
    return SBE_NULLVALUE_UINT16;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_templateId_min_value(void)
{
    return (uint16_t)0;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_templateId_max_value(void)
{
    return (uint16_t)65534;
}

SBE_ONE_DEF size_t aeron_archive_client_messageHeader_templateId_encoding_length(void)
{
    return 2;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_templateId(
    const struct aeron_archive_client_messageHeader *const codec)
{
    uint16_t val;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(&val, codec->buffer + codec->offset + 2, sizeof(uint16_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return SBE_LITTLE_ENDIAN_ENCODE_16(val);
}

SBE_ONE_DEF struct aeron_archive_client_messageHeader *aeron_archive_client_messageHeader_set_templateId(
    struct aeron_archive_client_messageHeader *const codec,
    const uint16_t value)
{
    uint16_t val = SBE_LITTLE_ENDIAN_ENCODE_16(value);
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(codec->buffer + codec->offset + 2, &val, sizeof(uint16_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return codec;
}

SBE_ONE_DEF const char *aeron_archive_client_messageHeader_schemaId_meta_attribute(
    const enum aeron_archive_client_messageHeader_meta_attribute attribute)
{
    switch (attribute)
    {
        case aeron_archive_client_messageHeader_meta_attribute_EPOCH: return "";
        case aeron_archive_client_messageHeader_meta_attribute_TIME_UNIT: return "";
        case aeron_archive_client_messageHeader_meta_attribute_SEMANTIC_TYPE: return "";
        case aeron_archive_client_messageHeader_meta_attribute_PRESENCE: return "required";
    }

    return "";
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_schemaId_id(void)
{
    return -1;
}

SBE_ONE_DEF uint64_t aeron_archive_client_messageHeader_schemaId_since_version(void)
{
    return 0;
}

SBE_ONE_DEF bool aeron_archive_client_messageHeader_schemaId_in_acting_version(
    const struct aeron_archive_client_messageHeader *const codec)
{
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
    return codec->acting_version >= aeron_archive_client_messageHeader_schemaId_since_version();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
}

SBE_ONE_DEF size_t aeron_archive_client_messageHeader_schemaId_encoding_offset(void)
{
    return 4;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_schemaId_null_value(void)
{
    return SBE_NULLVALUE_UINT16;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_schemaId_min_value(void)
{
    return (uint16_t)0;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_schemaId_max_value(void)
{
    return (uint16_t)65534;
}

SBE_ONE_DEF size_t aeron_archive_client_messageHeader_schemaId_encoding_length(void)
{
    return 2;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_schemaId(
    const struct aeron_archive_client_messageHeader *const codec)
{
    uint16_t val;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(&val, codec->buffer + codec->offset + 4, sizeof(uint16_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return SBE_LITTLE_ENDIAN_ENCODE_16(val);
}

SBE_ONE_DEF struct aeron_archive_client_messageHeader *aeron_archive_client_messageHeader_set_schemaId(
    struct aeron_archive_client_messageHeader *const codec,
    const uint16_t value)
{
    uint16_t val = SBE_LITTLE_ENDIAN_ENCODE_16(value);
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(codec->buffer + codec->offset + 4, &val, sizeof(uint16_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return codec;
}

SBE_ONE_DEF const char *aeron_archive_client_messageHeader_version_meta_attribute(
    const enum aeron_archive_client_messageHeader_meta_attribute attribute)
{
    switch (attribute)
    {
        case aeron_archive_client_messageHeader_meta_attribute_EPOCH: return "";
        case aeron_archive_client_messageHeader_meta_attribute_TIME_UNIT: return "";
        case aeron_archive_client_messageHeader_meta_attribute_SEMANTIC_TYPE: return "";
        case aeron_archive_client_messageHeader_meta_attribute_PRESENCE: return "required";
    }

    return "";
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_version_id(void)
{
    return -1;
}

SBE_ONE_DEF uint64_t aeron_archive_client_messageHeader_version_since_version(void)
{
    return 0;
}

SBE_ONE_DEF bool aeron_archive_client_messageHeader_version_in_acting_version(
    const struct aeron_archive_client_messageHeader *const codec)
{
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
    return codec->acting_version >= aeron_archive_client_messageHeader_version_since_version();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
}

SBE_ONE_DEF size_t aeron_archive_client_messageHeader_version_encoding_offset(void)
{
    return 6;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_version_null_value(void)
{
    return SBE_NULLVALUE_UINT16;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_version_min_value(void)
{
    return (uint16_t)0;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_version_max_value(void)
{
    return (uint16_t)65534;
}

SBE_ONE_DEF size_t aeron_archive_client_messageHeader_version_encoding_length(void)
{
    return 2;
}

SBE_ONE_DEF uint16_t aeron_archive_client_messageHeader_version(
    const struct aeron_archive_client_messageHeader *const codec)
{
    uint16_t val;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(&val, codec->buffer + codec->offset + 6, sizeof(uint16_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return SBE_LITTLE_ENDIAN_ENCODE_16(val);
}

SBE_ONE_DEF struct aeron_archive_client_messageHeader *aeron_archive_client_messageHeader_set_version(
    struct aeron_archive_client_messageHeader *const codec,
    const uint16_t value)
{
    uint16_t val = SBE_LITTLE_ENDIAN_ENCODE_16(value);
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(codec->buffer + codec->offset + 6, &val, sizeof(uint16_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return codec;
}

#endif
