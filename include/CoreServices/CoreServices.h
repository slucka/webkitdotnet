/*
 * Copyright (c) 2007 Apple Inc.
 * All rights reserved.
 *
 */

#pragma once

#include <CoreFoundation/CoreFoundation.h>
#include <ConditionalMacros.h>
#include <windows.h>
#include <stdio.h>

/* Types */

#define STACK_UPP_TYPE(name) name

typedef SInt32                          Fixed;

typedef unsigned char                   Str63[64];

typedef char *                          Ptr;
typedef Ptr *                           Handle;

#ifndef nil
    #define nil 0
#endif


/* Endianness */

#define Endian16_Swap(value)                 \
        (((((UInt16)value)<<8) & 0xFF00)   | \
         ((((UInt16)value)>>8) & 0x00FF))

#define Endian32_Swap(value)                     \
        (((((UInt32)value)<<24) & 0xFF000000)  | \
         ((((UInt32)value)<< 8) & 0x00FF0000)  | \
         ((((UInt32)value)>> 8) & 0x0000FF00)  | \
         ((((UInt32)value)>>24) & 0x000000FF))


__inline UInt32 SwapU32(UInt32 x)
{
    return ((x << 24) & 0xFF000000) |
           ((x <<  8) & 0x00FF0000) |
           ((x >>  8) & 0x0000FF00) |
           ((x >> 24) & 0x000000FF) ;
}

__inline UInt16 SwapU16(UInt16 x)
{
    return (x << 8) | (x >> 8);
}

#define EndianU32_BtoN(x) SwapU32(x)
#define EndianU16_BtoN(x) SwapU16(x)
#define EndianS32_BtoN(x) ((SInt32)SwapU32(x))
#define EndianS16_BtoN(x) ((SInt16)SwapU16(x))

#define EndianU32_NtoB(x) EndianU32_BtoN(x)
#define EndianU16_NtoB(x) EndianU16_BtoN(x)
#define EndianS32_NtoB(x) EndianS32_BtoN(x)
#define EndianS16_NtoB(x) EndianS16_BtoN(x)

#define EndianU32_LtoN(x) x
#define EndianU16_LtoN(x) x
#define EndianS32_LtoN(x) x
#define EndianS16_LtoN(x) x

#define EndianU32_NtoL(x) x
#define EndianU16_NtoL(x) x
#define EndianS32_NtoL(x) x
#define EndianS16_NtoL(x) x

__inline uint16_t OSReadSwapInt16(const volatile void * base, uintptr_t byteOffset)
{
    uint16_t result;
    volatile uint16_t *addr = (volatile uint16_t *)((uintptr_t)base + byteOffset);
	result = *addr;
	return SwapU16(result);
}

__inline uint32_t OSReadSwapInt32(const volatile void * base, uintptr_t byteOffset)
{
    uint32_t result;
    volatile uint32_t *addr = (volatile uint32_t *)((uintptr_t)base + byteOffset);
	result = *addr;
	return SwapU32(result);
}


/* Meta script codes:*/
enum {
  smSystemScript                = -1,   /* designates system script.*/
  smCurrentScript               = -2,   /* designates current font script.*/
  smAllScripts                  = -3,   /* designates any script*/

  smRoman                       = 0,
};


/* Error codes */

enum {
  noErr                         = 0,
  unimpErr                      = -4,   /*unimplemented core routine*/
  writErr                       = -20,  /*I/O System Errors*/
  ioErr                         = -36,  /*I/O error (bummers)*/
  fnOpnErr                      = -38,  /*File not open*/
  eofErr                        = -39,  /*End of file*/
  fnfErr                        = -43,  /*File not found*/
  dupFNErr                      = -48,  /*duplicate filename (rename)*/
  paramErr                      = -50,  /*error in user parameter list*/
  permErr                       = -54,  /*permissions error (on file open)*/
  memFullErr                    = -108, /*Not enough room in heap zone*/
  nilHandleErr                  = -109, /*Master Pointer was NIL in HandleZone or other*/
  memAdrErr                     = -110, /*address was odd; or out of range*/
  memPCErr                      = -114, /*Pointer Check failed*/
  memBCErr                      = -115, /*Block Check failed*/
  dirNFErr                      = -120, /*Directory not found*/
  userCanceledErr               = -128,
  resNotFound                   = -192, /*Resource not found*/
};

/* ColorSync Result codes */
enum {
                                        /* Profile Access Errors */
  cmElementTagNotFound          = -4200,
  cmIndexRangeErr               = -4201, /* Tag index out of range */
  cmCantDeleteElement           = -4202,
  cmFatalProfileErr             = -4203,
  cmInvalidProfile              = -4204, /* A Profile must contain a 'cs1 ' tag to be valid */
  cmInvalidProfileLocation      = -4205, /* Operation not supported for this profile location */
  cmCantCopyModifiedV1Profile   = -4215, /* Illegal to copy version 1 profiles that have been modified */
                                        /* Profile Search Errors */
  cmInvalidSearch               = -4206, /* Bad Search Handle */
  cmSearchError                 = -4207,
  cmErrIncompatibleProfile      = -4208, /* Other ColorSync Errors */
  cmInvalidColorSpace           = -4209, /* Profile colorspace does not match bitmap type */
  cmInvalidSrcMap               = -4210, /* Source pix/bit map was invalid */
  cmInvalidDstMap               = -4211, /* Destination pix/bit map was invalid */
  cmNoGDevicesError             = -4212, /* Begin/End Matching -- no gdevices available */
  cmInvalidProfileComment       = -4213, /* Bad Profile comment during drawpicture */
  cmRangeOverFlow               = -4214, /* Color conversion warning that some output color values over/underflowed and were clipped */
  cmNamedColorNotFound          = -4216, /* NamedColor not found */
  cmCantGamutCheckError         = -4217 /* Gammut checking not supported by this ColorWorld */
};

/* ColorSync Result codes */
enum {
                                        /* General Errors */
  cmProfileError                = -170,
  cmMethodError                 = -171,
  cmMethodNotFound              = -175, /* CMM not present */
  cmProfileNotFound             = -176, /* Responder error */
  cmProfilesIdentical           = -177, /* Profiles the same */
  cmCantConcatenateError        = -178, /* Profile can't be concatenated */
  cmCantXYZ                     = -179, /* CMM cant handle XYZ space */
  cmCantDeleteProfile           = -180, /* Responder error */
  cmUnsupportedDataType         = -181, /* Responder error */
  cmNoCurrentProfile            = -182  /* Responder error */
};


/* Versions */

enum {
  gestaltColorMatchingVersion   = 'cmtc',
  gestaltColorSync10            = 0x0100, /* 0x0100 & 0x0110 _Gestalt versions for 1.0-1.0.3 product */
  gestaltColorSync11            = 0x0110, /*   0x0100 == low-level matching only */
  gestaltColorSync104           = 0x0104, /* Real version, by popular demand */
  gestaltColorSync105           = 0x0105,
  gestaltColorSync20            = 0x0200, /* ColorSync 2.0 */
  gestaltColorSync21            = 0x0210,
  gestaltColorSync211           = 0x0211,
  gestaltColorSync212           = 0x0212,
  gestaltColorSync213           = 0x0213,
  gestaltColorSync25            = 0x0250,
  gestaltColorSync26            = 0x0260,
  gestaltColorSync261           = 0x0261,
  gestaltColorSync30            = 0x0300
};


/* Constants */

enum {
	kUnknownType                  = 0x3F3F3F3F /* "????" QuickTime 3.0: default unknown ResType or OSType */
};


/* Assert Macros */

__inline void FormatOutputDebugString(const char* format, ...)
{
	char buffer[1024] = "";
	va_list args;
	va_start(args, format);
	vsnprintf_s(buffer, sizeof(buffer), _TRUNCATE, format, args);
	va_end(args);
	OutputDebugStringA(buffer);
}
#define DEBUG_ASSERT_MESSAGE(name, assertion, label, message, file, line, value) \
	FormatOutputDebugString("AssertMacros: %s, %s file: %s, line: %d\n", assertion, (message!=0) ? message : "", file, line);

#include <AssertMacros.h>

#if defined(_MSC_VER)
    #ifdef __cplusplus
        extern "C" {
    #endif
        int digittoint (int c);                                 /* defined in CGWindows.c" */
        size_t strlcat(char* dst, const char* src, size_t size);/* defined in CGWindows.c" */
        void* reallocf(void* ptr, size_t size);                 /* defined in CGWindows.c" */
    #ifdef __cplusplus
        }
    #endif
#endif


