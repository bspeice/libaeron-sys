/* Generated SBE (Simple Binary Encoding) message codec */

#ifndef _AERON_ARCHIVE_CLIENT_REPLAYREQUEST_H_
#define _AERON_ARCHIVE_CLIENT_REPLAYREQUEST_H_

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

#include "sourceLocation.h"
#include "messageHeader.h"
#include "booleanType.h"
#include "recordingSignal.h"
#include "controlResponseCode.h"
#include "recordingState.h"
#include "varAsciiEncoding.h"
#include "varDataEncoding.h"

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

struct aeron_archive_client_replayRequest
{
    char *buffer;
    uint64_t buffer_length;
    uint64_t offset;
    uint64_t position;
    uint64_t acting_block_length;
    uint64_t acting_version;
};

enum aeron_archive_client_replayRequest_meta_attribute
{
    aeron_archive_client_replayRequest_meta_attribute_EPOCH,
    aeron_archive_client_replayRequest_meta_attribute_TIME_UNIT,
    aeron_archive_client_replayRequest_meta_attribute_SEMANTIC_TYPE,
    aeron_archive_client_replayRequest_meta_attribute_PRESENCE
};

union aeron_archive_client_replayRequest_float_as_uint
{
    float fp_value;
    uint32_t uint_value;
};

union aeron_archive_client_replayRequest_double_as_uint
{
    double fp_value;
    uint64_t uint_value;
};

struct aeron_archive_client_replayRequest_string_view
{
    const char* data;
    size_t length;
};

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_sbe_position(
    const struct aeron_archive_client_replayRequest *const codec)
{
    return codec->position;
}

SBE_ONE_DEF bool aeron_archive_client_replayRequest_set_sbe_position(
    struct aeron_archive_client_replayRequest *const codec,
    const uint64_t position)
{
    if (SBE_BOUNDS_CHECK_EXPECT((position > codec->buffer_length), false))
    {
        errno = E100;
        return false;
    }
    codec->position = position;

    return true;
}

SBE_ONE_DEF uint64_t *aeron_archive_client_replayRequest_sbe_position_ptr(
    struct aeron_archive_client_replayRequest *const codec)
{
    return &codec->position;
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest *aeron_archive_client_replayRequest_reset(
    struct aeron_archive_client_replayRequest *const codec,
    char *buffer,
    const uint64_t offset,
    const uint64_t buffer_length,
    const uint64_t acting_block_length,
    const uint64_t acting_version)
{
    codec->buffer = buffer;
    codec->offset = offset;
    codec->buffer_length = buffer_length;
    codec->acting_block_length = acting_block_length;
    codec->acting_version = acting_version;
    if (!aeron_archive_client_replayRequest_set_sbe_position(codec, offset + acting_block_length))
    {
        return NULL;
    }

    return codec;
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest *aeron_archive_client_replayRequest_copy(
    struct aeron_archive_client_replayRequest *const codec,
    const struct aeron_archive_client_replayRequest *const other)
{
     codec->buffer = other->buffer;
     codec->offset = other->offset;
     codec->buffer_length = other->buffer_length;
     codec->acting_block_length = other->acting_block_length;
     codec->acting_version = other->acting_version;
     codec->position = other->position;

     return codec;
}

SBE_ONE_DEF uint16_t aeron_archive_client_replayRequest_sbe_block_length(void)
{
    return (uint16_t)56;
}

#define AERON_ARCHIVE_CLIENT_REPLAY_REQUEST_SBE_TEMPLATE_ID (uint16_t)6

SBE_ONE_DEF uint16_t aeron_archive_client_replayRequest_sbe_template_id(void)
{
    return (uint16_t)6;
}

SBE_ONE_DEF uint16_t aeron_archive_client_replayRequest_sbe_schema_id(void)
{
    return (uint16_t)101;
}

SBE_ONE_DEF uint16_t aeron_archive_client_replayRequest_sbe_schema_version(void)
{
    return (uint16_t)13;
}

SBE_ONE_DEF const char* aeron_archive_client_replayRequest_sbe_semantic_version(void)
{
    return "5.2";
}

SBE_ONE_DEF const char *aeron_archive_client_replayRequest_sbe_semantic_type(void)
{
    return "";
}

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_offset(
    const struct aeron_archive_client_replayRequest *const codec)
{
    return codec->offset;
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest *aeron_archive_client_replayRequest_wrap_and_apply_header(
    struct aeron_archive_client_replayRequest *const codec,
    char *buffer,
    const uint64_t offset,
    const uint64_t buffer_length,
    struct aeron_archive_client_messageHeader *const hdr)
{
    aeron_archive_client_messageHeader_wrap(
        hdr, buffer + offset, 0, aeron_archive_client_messageHeader_sbe_schema_version(), buffer_length);

    aeron_archive_client_messageHeader_set_blockLength(hdr, aeron_archive_client_replayRequest_sbe_block_length());
    aeron_archive_client_messageHeader_set_templateId(hdr, aeron_archive_client_replayRequest_sbe_template_id());
    aeron_archive_client_messageHeader_set_schemaId(hdr, aeron_archive_client_replayRequest_sbe_schema_id());
    aeron_archive_client_messageHeader_set_version(hdr, aeron_archive_client_replayRequest_sbe_schema_version());

    aeron_archive_client_replayRequest_reset(
        codec,
        buffer + offset + aeron_archive_client_messageHeader_encoded_length(),
        0,
        buffer_length - aeron_archive_client_messageHeader_encoded_length(),
        aeron_archive_client_replayRequest_sbe_block_length(),
        aeron_archive_client_replayRequest_sbe_schema_version());

    return codec;
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest *aeron_archive_client_replayRequest_wrap_for_encode(
    struct aeron_archive_client_replayRequest *const codec,
    char *buffer,
    const uint64_t offset,
    const uint64_t buffer_length)
{
    return aeron_archive_client_replayRequest_reset(
        codec,
        buffer,
        offset,
        buffer_length,
        aeron_archive_client_replayRequest_sbe_block_length(),
        aeron_archive_client_replayRequest_sbe_schema_version());
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest *aeron_archive_client_replayRequest_wrap_for_decode(
    struct aeron_archive_client_replayRequest *const codec,
    char *buffer,
    const uint64_t offset,
    const uint64_t acting_block_length,
    const uint64_t acting_version,
    const uint64_t buffer_length)
{
    return aeron_archive_client_replayRequest_reset(
        codec,
        buffer,
        offset,
        buffer_length,
        acting_block_length,
        acting_version);
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest *aeron_archive_client_replayRequest_sbe_rewind(
    struct aeron_archive_client_replayRequest *const codec)
{
    return aeron_archive_client_replayRequest_wrap_for_decode(
        codec,
        codec->buffer,
        codec->offset,
        codec->acting_block_length,
        codec->acting_version,
        codec->buffer_length);
}

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_encoded_length(
    const struct aeron_archive_client_replayRequest *const codec)
{
    return aeron_archive_client_replayRequest_sbe_position(codec) - codec->offset;
}

SBE_ONE_DEF const char *aeron_archive_client_replayRequest_buffer(
    const struct aeron_archive_client_replayRequest *const codec)
{
    return codec->buffer;
}

SBE_ONE_DEF char *aeron_archive_client_replayRequest_mut_buffer(
    struct aeron_archive_client_replayRequest *const codec)
{
    return codec->buffer;
}

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_buffer_length(
    const struct aeron_archive_client_replayRequest *const codec)
{
    return codec->buffer_length;
}

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_acting_version(
    const struct aeron_archive_client_replayRequest *const codec)
{
    return codec->acting_version;
}

SBE_ONE_DEF const char *aeron_archive_client_replayRequest_controlSessionId_meta_attribute(
    const enum aeron_archive_client_replayRequest_meta_attribute attribute)
{
    switch (attribute)
    {
        case aeron_archive_client_replayRequest_meta_attribute_EPOCH: return "";
        case aeron_archive_client_replayRequest_meta_attribute_TIME_UNIT: return "";
        case aeron_archive_client_replayRequest_meta_attribute_SEMANTIC_TYPE: return "";
        case aeron_archive_client_replayRequest_meta_attribute_PRESENCE: return "required";
    }

    return "";
}

SBE_ONE_DEF uint16_t aeron_archive_client_replayRequest_controlSessionId_id(void)
{
    return 1;
}

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_controlSessionId_since_version(void)
{
    return 0;
}

SBE_ONE_DEF bool aeron_archive_client_replayRequest_controlSessionId_in_acting_version(
    const struct aeron_archive_client_replayRequest *const codec)
{
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
    return codec->acting_version >= aeron_archive_client_replayRequest_controlSessionId_since_version();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_controlSessionId_encoding_offset(void)
{
    return 0;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_controlSessionId_null_value(void)
{
    return SBE_NULLVALUE_INT64;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_controlSessionId_min_value(void)
{
    return INT64_C(-9223372036854775807);
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_controlSessionId_max_value(void)
{
    return INT64_C(9223372036854775807);
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_controlSessionId_encoding_length(void)
{
    return 8;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_controlSessionId(
    const struct aeron_archive_client_replayRequest *const codec)
{
    int64_t val;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(&val, codec->buffer + codec->offset + 0, sizeof(int64_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return SBE_LITTLE_ENDIAN_ENCODE_64(val);
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest *aeron_archive_client_replayRequest_set_controlSessionId(
    struct aeron_archive_client_replayRequest *const codec,
    const int64_t value)
{
    int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(codec->buffer + codec->offset + 0, &val, sizeof(int64_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return codec;
}

SBE_ONE_DEF const char *aeron_archive_client_replayRequest_correlationId_meta_attribute(
    const enum aeron_archive_client_replayRequest_meta_attribute attribute)
{
    switch (attribute)
    {
        case aeron_archive_client_replayRequest_meta_attribute_EPOCH: return "";
        case aeron_archive_client_replayRequest_meta_attribute_TIME_UNIT: return "";
        case aeron_archive_client_replayRequest_meta_attribute_SEMANTIC_TYPE: return "";
        case aeron_archive_client_replayRequest_meta_attribute_PRESENCE: return "required";
    }

    return "";
}

SBE_ONE_DEF uint16_t aeron_archive_client_replayRequest_correlationId_id(void)
{
    return 2;
}

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_correlationId_since_version(void)
{
    return 0;
}

SBE_ONE_DEF bool aeron_archive_client_replayRequest_correlationId_in_acting_version(
    const struct aeron_archive_client_replayRequest *const codec)
{
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
    return codec->acting_version >= aeron_archive_client_replayRequest_correlationId_since_version();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_correlationId_encoding_offset(void)
{
    return 8;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_correlationId_null_value(void)
{
    return SBE_NULLVALUE_INT64;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_correlationId_min_value(void)
{
    return INT64_C(-9223372036854775807);
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_correlationId_max_value(void)
{
    return INT64_C(9223372036854775807);
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_correlationId_encoding_length(void)
{
    return 8;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_correlationId(
    const struct aeron_archive_client_replayRequest *const codec)
{
    int64_t val;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(&val, codec->buffer + codec->offset + 8, sizeof(int64_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return SBE_LITTLE_ENDIAN_ENCODE_64(val);
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest *aeron_archive_client_replayRequest_set_correlationId(
    struct aeron_archive_client_replayRequest *const codec,
    const int64_t value)
{
    int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(codec->buffer + codec->offset + 8, &val, sizeof(int64_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return codec;
}

SBE_ONE_DEF const char *aeron_archive_client_replayRequest_recordingId_meta_attribute(
    const enum aeron_archive_client_replayRequest_meta_attribute attribute)
{
    switch (attribute)
    {
        case aeron_archive_client_replayRequest_meta_attribute_EPOCH: return "";
        case aeron_archive_client_replayRequest_meta_attribute_TIME_UNIT: return "";
        case aeron_archive_client_replayRequest_meta_attribute_SEMANTIC_TYPE: return "";
        case aeron_archive_client_replayRequest_meta_attribute_PRESENCE: return "required";
    }

    return "";
}

SBE_ONE_DEF uint16_t aeron_archive_client_replayRequest_recordingId_id(void)
{
    return 3;
}

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_recordingId_since_version(void)
{
    return 0;
}

SBE_ONE_DEF bool aeron_archive_client_replayRequest_recordingId_in_acting_version(
    const struct aeron_archive_client_replayRequest *const codec)
{
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
    return codec->acting_version >= aeron_archive_client_replayRequest_recordingId_since_version();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_recordingId_encoding_offset(void)
{
    return 16;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_recordingId_null_value(void)
{
    return SBE_NULLVALUE_INT64;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_recordingId_min_value(void)
{
    return INT64_C(-9223372036854775807);
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_recordingId_max_value(void)
{
    return INT64_C(9223372036854775807);
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_recordingId_encoding_length(void)
{
    return 8;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_recordingId(
    const struct aeron_archive_client_replayRequest *const codec)
{
    int64_t val;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(&val, codec->buffer + codec->offset + 16, sizeof(int64_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return SBE_LITTLE_ENDIAN_ENCODE_64(val);
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest *aeron_archive_client_replayRequest_set_recordingId(
    struct aeron_archive_client_replayRequest *const codec,
    const int64_t value)
{
    int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(codec->buffer + codec->offset + 16, &val, sizeof(int64_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return codec;
}

SBE_ONE_DEF const char *aeron_archive_client_replayRequest_position_meta_attribute(
    const enum aeron_archive_client_replayRequest_meta_attribute attribute)
{
    switch (attribute)
    {
        case aeron_archive_client_replayRequest_meta_attribute_EPOCH: return "";
        case aeron_archive_client_replayRequest_meta_attribute_TIME_UNIT: return "";
        case aeron_archive_client_replayRequest_meta_attribute_SEMANTIC_TYPE: return "";
        case aeron_archive_client_replayRequest_meta_attribute_PRESENCE: return "required";
    }

    return "";
}

SBE_ONE_DEF uint16_t aeron_archive_client_replayRequest_position_id(void)
{
    return 4;
}

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_position_since_version(void)
{
    return 0;
}

SBE_ONE_DEF bool aeron_archive_client_replayRequest_position_in_acting_version(
    const struct aeron_archive_client_replayRequest *const codec)
{
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
    return codec->acting_version >= aeron_archive_client_replayRequest_position_since_version();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_position_encoding_offset(void)
{
    return 24;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_position_null_value(void)
{
    return SBE_NULLVALUE_INT64;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_position_min_value(void)
{
    return INT64_C(-9223372036854775807);
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_position_max_value(void)
{
    return INT64_C(9223372036854775807);
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_position_encoding_length(void)
{
    return 8;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_position(
    const struct aeron_archive_client_replayRequest *const codec)
{
    int64_t val;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(&val, codec->buffer + codec->offset + 24, sizeof(int64_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return SBE_LITTLE_ENDIAN_ENCODE_64(val);
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest *aeron_archive_client_replayRequest_set_position(
    struct aeron_archive_client_replayRequest *const codec,
    const int64_t value)
{
    int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(codec->buffer + codec->offset + 24, &val, sizeof(int64_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return codec;
}

SBE_ONE_DEF const char *aeron_archive_client_replayRequest_length_meta_attribute(
    const enum aeron_archive_client_replayRequest_meta_attribute attribute)
{
    switch (attribute)
    {
        case aeron_archive_client_replayRequest_meta_attribute_EPOCH: return "";
        case aeron_archive_client_replayRequest_meta_attribute_TIME_UNIT: return "";
        case aeron_archive_client_replayRequest_meta_attribute_SEMANTIC_TYPE: return "";
        case aeron_archive_client_replayRequest_meta_attribute_PRESENCE: return "required";
    }

    return "";
}

SBE_ONE_DEF uint16_t aeron_archive_client_replayRequest_length_id(void)
{
    return 5;
}

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_length_since_version(void)
{
    return 0;
}

SBE_ONE_DEF bool aeron_archive_client_replayRequest_length_in_acting_version(
    const struct aeron_archive_client_replayRequest *const codec)
{
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
    return codec->acting_version >= aeron_archive_client_replayRequest_length_since_version();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_length_encoding_offset(void)
{
    return 32;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_length_null_value(void)
{
    return SBE_NULLVALUE_INT64;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_length_min_value(void)
{
    return INT64_C(-9223372036854775807);
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_length_max_value(void)
{
    return INT64_C(9223372036854775807);
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_length_encoding_length(void)
{
    return 8;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_length(
    const struct aeron_archive_client_replayRequest *const codec)
{
    int64_t val;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(&val, codec->buffer + codec->offset + 32, sizeof(int64_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return SBE_LITTLE_ENDIAN_ENCODE_64(val);
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest *aeron_archive_client_replayRequest_set_length(
    struct aeron_archive_client_replayRequest *const codec,
    const int64_t value)
{
    int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(codec->buffer + codec->offset + 32, &val, sizeof(int64_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return codec;
}

SBE_ONE_DEF const char *aeron_archive_client_replayRequest_replayStreamId_meta_attribute(
    const enum aeron_archive_client_replayRequest_meta_attribute attribute)
{
    switch (attribute)
    {
        case aeron_archive_client_replayRequest_meta_attribute_EPOCH: return "";
        case aeron_archive_client_replayRequest_meta_attribute_TIME_UNIT: return "";
        case aeron_archive_client_replayRequest_meta_attribute_SEMANTIC_TYPE: return "";
        case aeron_archive_client_replayRequest_meta_attribute_PRESENCE: return "required";
    }

    return "";
}

SBE_ONE_DEF uint16_t aeron_archive_client_replayRequest_replayStreamId_id(void)
{
    return 6;
}

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_replayStreamId_since_version(void)
{
    return 0;
}

SBE_ONE_DEF bool aeron_archive_client_replayRequest_replayStreamId_in_acting_version(
    const struct aeron_archive_client_replayRequest *const codec)
{
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
    return codec->acting_version >= aeron_archive_client_replayRequest_replayStreamId_since_version();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_replayStreamId_encoding_offset(void)
{
    return 40;
}

SBE_ONE_DEF int32_t aeron_archive_client_replayRequest_replayStreamId_null_value(void)
{
    return SBE_NULLVALUE_INT32;
}

SBE_ONE_DEF int32_t aeron_archive_client_replayRequest_replayStreamId_min_value(void)
{
    return INT32_C(-2147483647);
}

SBE_ONE_DEF int32_t aeron_archive_client_replayRequest_replayStreamId_max_value(void)
{
    return INT32_C(2147483647);
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_replayStreamId_encoding_length(void)
{
    return 4;
}

SBE_ONE_DEF int32_t aeron_archive_client_replayRequest_replayStreamId(
    const struct aeron_archive_client_replayRequest *const codec)
{
    int32_t val;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(&val, codec->buffer + codec->offset + 40, sizeof(int32_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return SBE_LITTLE_ENDIAN_ENCODE_32(val);
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest *aeron_archive_client_replayRequest_set_replayStreamId(
    struct aeron_archive_client_replayRequest *const codec,
    const int32_t value)
{
    int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(codec->buffer + codec->offset + 40, &val, sizeof(int32_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return codec;
}

SBE_ONE_DEF const char *aeron_archive_client_replayRequest_fileIoMaxLength_meta_attribute(
    const enum aeron_archive_client_replayRequest_meta_attribute attribute)
{
    switch (attribute)
    {
        case aeron_archive_client_replayRequest_meta_attribute_EPOCH: return "";
        case aeron_archive_client_replayRequest_meta_attribute_TIME_UNIT: return "";
        case aeron_archive_client_replayRequest_meta_attribute_SEMANTIC_TYPE: return "";
        case aeron_archive_client_replayRequest_meta_attribute_PRESENCE: return "required";
    }

    return "";
}

SBE_ONE_DEF uint16_t aeron_archive_client_replayRequest_fileIoMaxLength_id(void)
{
    return 8;
}

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_fileIoMaxLength_since_version(void)
{
    return 7;
}

SBE_ONE_DEF bool aeron_archive_client_replayRequest_fileIoMaxLength_in_acting_version(
    const struct aeron_archive_client_replayRequest *const codec)
{
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
    return codec->acting_version >= aeron_archive_client_replayRequest_fileIoMaxLength_since_version();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_fileIoMaxLength_encoding_offset(void)
{
    return 44;
}

SBE_ONE_DEF int32_t aeron_archive_client_replayRequest_fileIoMaxLength_null_value(void)
{
    return SBE_NULLVALUE_INT32;
}

SBE_ONE_DEF int32_t aeron_archive_client_replayRequest_fileIoMaxLength_min_value(void)
{
    return INT32_C(-2147483647);
}

SBE_ONE_DEF int32_t aeron_archive_client_replayRequest_fileIoMaxLength_max_value(void)
{
    return INT32_C(2147483647);
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_fileIoMaxLength_encoding_length(void)
{
    return 4;
}

SBE_ONE_DEF int32_t aeron_archive_client_replayRequest_fileIoMaxLength(
    const struct aeron_archive_client_replayRequest *const codec)
{
    if (codec->acting_version < 7)
    {
        return INT32_MIN;
    }

    int32_t val;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(&val, codec->buffer + codec->offset + 44, sizeof(int32_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return SBE_LITTLE_ENDIAN_ENCODE_32(val);
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest *aeron_archive_client_replayRequest_set_fileIoMaxLength(
    struct aeron_archive_client_replayRequest *const codec,
    const int32_t value)
{
    int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(codec->buffer + codec->offset + 44, &val, sizeof(int32_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return codec;
}

SBE_ONE_DEF const char *aeron_archive_client_replayRequest_replayToken_meta_attribute(
    const enum aeron_archive_client_replayRequest_meta_attribute attribute)
{
    switch (attribute)
    {
        case aeron_archive_client_replayRequest_meta_attribute_EPOCH: return "";
        case aeron_archive_client_replayRequest_meta_attribute_TIME_UNIT: return "";
        case aeron_archive_client_replayRequest_meta_attribute_SEMANTIC_TYPE: return "";
        case aeron_archive_client_replayRequest_meta_attribute_PRESENCE: return "required";
    }

    return "";
}

SBE_ONE_DEF uint16_t aeron_archive_client_replayRequest_replayToken_id(void)
{
    return 9;
}

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_replayToken_since_version(void)
{
    return 10;
}

SBE_ONE_DEF bool aeron_archive_client_replayRequest_replayToken_in_acting_version(
    const struct aeron_archive_client_replayRequest *const codec)
{
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
    return codec->acting_version >= aeron_archive_client_replayRequest_replayToken_since_version();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_replayToken_encoding_offset(void)
{
    return 48;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_replayToken_null_value(void)
{
    return SBE_NULLVALUE_INT64;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_replayToken_min_value(void)
{
    return INT64_C(-9223372036854775807);
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_replayToken_max_value(void)
{
    return INT64_C(9223372036854775807);
}

SBE_ONE_DEF size_t aeron_archive_client_replayRequest_replayToken_encoding_length(void)
{
    return 8;
}

SBE_ONE_DEF int64_t aeron_archive_client_replayRequest_replayToken(
    const struct aeron_archive_client_replayRequest *const codec)
{
    if (codec->acting_version < 10)
    {
        return INT64_MIN;
    }

    int64_t val;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(&val, codec->buffer + codec->offset + 48, sizeof(int64_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return SBE_LITTLE_ENDIAN_ENCODE_64(val);
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest *aeron_archive_client_replayRequest_set_replayToken(
    struct aeron_archive_client_replayRequest *const codec,
    const int64_t value)
{
    int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    memcpy(codec->buffer + codec->offset + 48, &val, sizeof(int64_t));
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return codec;
}

SBE_ONE_DEF const char *aeron_archive_client_replayRequest_replayChannel_meta_attribute(
    const enum aeron_archive_client_replayRequest_meta_attribute attribute)
{
    switch (attribute)
    {
        case aeron_archive_client_replayRequest_meta_attribute_EPOCH: return "";
        case aeron_archive_client_replayRequest_meta_attribute_TIME_UNIT: return "";
        case aeron_archive_client_replayRequest_meta_attribute_SEMANTIC_TYPE: return "";
        case aeron_archive_client_replayRequest_meta_attribute_PRESENCE: return "required";
    }

    return "";
}

SBE_ONE_DEF const char *aeron_archive_client_replayRequest_replayChannel_character_encoding(void)
{
    return "US-ASCII";
}

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_replayChannel_since_version(void)
{
    return 0;
}

SBE_ONE_DEF bool aeron_archive_client_replayRequest_replayChannel_in_acting_version(
    const struct aeron_archive_client_replayRequest *const codec)
{
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
    return codec->acting_version >= aeron_archive_client_replayRequest_replayChannel_since_version();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
}

SBE_ONE_DEF uint16_t aeron_archive_client_replayRequest_replayChannel_id(void)
{
    return 7;
}

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_replayChannel_header_length(void)
{
    return 4;
}

SBE_ONE_DEF uint32_t aeron_archive_client_replayRequest_replayChannel_length(
    const struct aeron_archive_client_replayRequest *const codec)
{
    uint32_t length;
    memcpy(&length, codec->buffer + aeron_archive_client_replayRequest_sbe_position(codec), sizeof(uint32_t));

    return SBE_LITTLE_ENDIAN_ENCODE_32(length);
}

SBE_ONE_DEF const char *aeron_archive_client_replayRequest_replayChannel(
    struct aeron_archive_client_replayRequest *const codec)
{
    uint32_t length_field_value;
    memcpy(&length_field_value, codec->buffer + aeron_archive_client_replayRequest_sbe_position(codec), sizeof(uint32_t));
    const char *field_ptr = (codec->buffer + aeron_archive_client_replayRequest_sbe_position(codec) + 4);

    if (!aeron_archive_client_replayRequest_set_sbe_position(
        codec, aeron_archive_client_replayRequest_sbe_position(codec) + 4 + SBE_LITTLE_ENDIAN_ENCODE_32(length_field_value)))
    {
        return NULL;
    }

    return field_ptr;
}

SBE_ONE_DEF uint64_t aeron_archive_client_replayRequest_get_replayChannel(
    struct aeron_archive_client_replayRequest *const codec,
    char *dst,
    const uint64_t length)
{
    uint64_t length_of_length_field = 4;
    uint64_t length_position = aeron_archive_client_replayRequest_sbe_position(codec);
    if (!aeron_archive_client_replayRequest_set_sbe_position(codec, length_position + length_of_length_field))
    {
        return 0;
    }

    uint32_t length_field_value;
    memcpy(&length_field_value, codec->buffer + length_position, sizeof(uint32_t));
    uint64_t data_length = SBE_LITTLE_ENDIAN_ENCODE_32(length_field_value);
    uint64_t bytes_to_copy = length < data_length ? length : data_length;
    uint64_t pos = aeron_archive_client_replayRequest_sbe_position(codec);

    if (!aeron_archive_client_replayRequest_set_sbe_position(codec, pos + data_length))
    {
        return 0;
    }

    memcpy(dst, codec->buffer + pos, bytes_to_copy);

    return bytes_to_copy;
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest_string_view aeron_archive_client_replayRequest_get_replayChannel_as_string_view(
    struct aeron_archive_client_replayRequest *const codec)
{
    uint32_t length_field_value = aeron_archive_client_replayRequest_replayChannel_length(codec);
    const char *field_ptr = codec->buffer + aeron_archive_client_replayRequest_sbe_position(codec) + 4;
    if (!aeron_archive_client_replayRequest_set_sbe_position(
        codec, aeron_archive_client_replayRequest_sbe_position(codec) + 4 + length_field_value))
    {
        struct aeron_archive_client_replayRequest_string_view ret = {NULL, 0};
        return ret;
    }

    struct aeron_archive_client_replayRequest_string_view ret = {field_ptr, length_field_value};

    return ret;
}

SBE_ONE_DEF struct aeron_archive_client_replayRequest *aeron_archive_client_replayRequest_put_replayChannel(
    struct aeron_archive_client_replayRequest *const codec,
    const char *src,
    const uint32_t length)
{
    uint64_t length_of_length_field = 4;
    uint64_t length_position = aeron_archive_client_replayRequest_sbe_position(codec);
    uint32_t length_field_value = SBE_LITTLE_ENDIAN_ENCODE_32(length);
    if (!aeron_archive_client_replayRequest_set_sbe_position(codec, length_position + length_of_length_field))
    {
        return NULL;
    }

    memcpy(codec->buffer + length_position, &length_field_value, sizeof(uint32_t));
    uint64_t pos = aeron_archive_client_replayRequest_sbe_position(codec);

    if (!aeron_archive_client_replayRequest_set_sbe_position(codec, pos + length))
    {
        return NULL;
    }

    memcpy(codec->buffer + pos, src, length);

    return codec;
}

#endif
