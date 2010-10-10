/*
	 File:	   CFNetwork/CFHTTPCookiesPriv.h
 
	 Contains:   CFType HTTPCookies header
 
	 Copyright:  Copyright (c) 2006-2008, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFHTTPCOOKIESPRIV__
#define __CFHTTPCOOKIESPRIV__

#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
#endif

#ifndef __COREFOUNDATION__
#include <CoreFoundation/CoreFoundation.h>
#endif




#include <Availability.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 2)

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint on
#endif

typedef struct OpaqueCFHTTPCookieStorage*  CFHTTPCookieStorageRef;
typedef struct OpaqueCFHTTPCookie*	  CFHTTPCookieRef;
enum {
  kCFHTTPCookieStorageAcceptPolicyAlways = 0,
  kCFHTTPCookieStorageAcceptPolicyNever = 1,
  kCFHTTPCookieStorageAcceptPolicyOnlyFromMainDocumentDomain = 2
};

enum {
  CFHTTPCookieStorageAcceptPolicyAlways = kCFHTTPCookieStorageAcceptPolicyAlways,
  CFHTTPCookieStorageAcceptPolicyNever = kCFHTTPCookieStorageAcceptPolicyNever,
  CFHTTPCookieStorageAcceptPolicyOnlyFromMainDocumentDomain = kCFHTTPCookieStorageAcceptPolicyOnlyFromMainDocumentDomain
};

typedef int							 CFHTTPCookieStorageAcceptPolicy;
enum CFHTTPCookieFlags {
  CFHTTPCookieSecureFlag		= 1 << 0,
  CFHTTPCookieSessionOnlyFlag   = 1 << 1,
  CFHTTPCookieHTTPOnlyFlag      = 1 << 2
};
typedef enum CFHTTPCookieFlags CFHTTPCookieFlags;

	
/*
 *  kCFHTTPCookieLocalFileDomain
 *   a special hostname to be used for cookies set by local file (file://) URLs
 */
CFN_EXPORT CFStringRef const kCFHTTPCookieLocalFileDomain		   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_3_0);

/*
 *  CFHTTPCookieGetTypeID()
 *  
 */
CFN_EXPORT CFTypeID 
CFHTTPCookieGetTypeID(void)								   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieCreateWithProperties()
 *  
 */
CFN_EXPORT CFHTTPCookieRef 
CFHTTPCookieCreateWithProperties(
  CFAllocatorRef	inAllocator,
  CFDictionaryRef   inProperties)							 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieCreateWithResponseHeaderFields()
 *  
 */
CFN_EXPORT CFArrayRef 
CFHTTPCookieCreateWithResponseHeaderFields(
  CFAllocatorRef	inAllocator,
  CFDictionaryRef   headerFields,
  CFURLRef		  inURL)									__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieCopyRequestHeaderFields()
 *  
 */
CFN_EXPORT CFDictionaryRef 
CFHTTPCookieCopyRequestHeaderFields(
  CFAllocatorRef   inAllocator,
  CFArrayRef	   inCookies)								 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieCopyProperties()
 *  
 */
CFN_EXPORT CFDictionaryRef 
CFHTTPCookieCopyProperties(CFHTTPCookieRef inCookie)		  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieGetVersion()
 *  
 */
CFN_EXPORT CFIndex 
CFHTTPCookieGetVersion(CFHTTPCookieRef inCookie)			  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieGetName()
 *  
 */
CFN_EXPORT CFStringRef 
CFHTTPCookieGetName(CFHTTPCookieRef inCookie)				 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieGetValue()
 *  
 */
CFN_EXPORT CFStringRef 
CFHTTPCookieGetValue(CFHTTPCookieRef inCookie)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieGetExpiratonDate()
 *  
 */
CFN_EXPORT CFDateRef 
CFHTTPCookieGetExpiratonDate(CFHTTPCookieRef inCookie)		__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieGetCreateDate()
 *  
 */
CFN_EXPORT CFDateRef 
CFHTTPCookieGetCreateDate(CFHTTPCookieRef inCookie)		   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieGetDomain()
 *  
 */
CFN_EXPORT CFStringRef 
CFHTTPCookieGetDomain(CFHTTPCookieRef inCookie)			   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieGetPath()
 *  
 */
CFN_EXPORT CFStringRef 
CFHTTPCookieGetPath(CFHTTPCookieRef inCookie)				 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieGetFlags()
 *  
 */
CFN_EXPORT unsigned int 
CFHTTPCookieGetFlags(CFHTTPCookieRef inCookie)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieGetComment()
 *  
 */
CFN_EXPORT CFStringRef 
CFHTTPCookieGetComment(CFHTTPCookieRef inCookie)			  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieGetCommentURL()
 *  
 */
CFN_EXPORT CFURLRef 
CFHTTPCookieGetCommentURL(CFHTTPCookieRef inCookie)		   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieGetPortArray()
 *  
 */
CFN_EXPORT CFArrayRef 
CFHTTPCookieGetPortArray(CFHTTPCookieRef inCookie)			__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


typedef CALLBACK_API_C( void , CFHTTPCookieStorageChangedProcPtr )(CFHTTPCookieStorageRef inStorage, void *context);
/*
 *  CFHTTPCookieStorageAddObserver()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageAddObserver(
  CFHTTPCookieStorageRef			  inStorage,
  CFRunLoopRef						inRunloop,
  CFStringRef						 inRunloopMode,
  CFHTTPCookieStorageChangedProcPtr   callback,
  void *							  context)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageRemoveObserver()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageRemoveObserver(
  CFHTTPCookieStorageRef			  inStorage,
  CFRunLoopRef						inRunloop,
  CFStringRef						 inRunloopMode,
  CFHTTPCookieStorageChangedProcPtr   callback,
  void *							  context)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageGetTypeID()
 *  
 */
CFN_EXPORT CFTypeID 
CFHTTPCookieStorageGetTypeID(void)							__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


struct CFHTTPCookieStorageFilterContext {
  CFIndex			 version;
  void *			  info;
  CFAllocatorRetainCallBack  retain;
  CFAllocatorReleaseCallBack  release;
  CFAllocatorCopyDescriptionCallBack  copyDescription;
};
typedef struct CFHTTPCookieStorageFilterContext CFHTTPCookieStorageFilterContext;
typedef CALLBACK_API_C( Boolean , CFHTTPCookieStorageFilterProcPtr )(CFHTTPCookieStorageRef inStorage, CFHTTPCookieRef inTestCookie, void *inInfo);
/*
 *  _CFHTTPCookieStorageGetDefault()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageRef 
_CFHTTPCookieStorageGetDefault(CFAllocatorRef inAllocator)	__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFHTTPCookieStorageCreateInMemory()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageRef 
_CFHTTPCookieStorageCreateInMemory(
  CFAllocatorRef					  inAllocator,
  CFHTTPCookieStorageRef			  baseStorage,
  CFHTTPCookieStorageFilterProcPtr	filterCallback,
  CFHTTPCookieStorageFilterContext *  context)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFHTTPCookieStorageCreateFromFile()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageRef 
_CFHTTPCookieStorageCreateFromFile(
  CFAllocatorRef					  inAllocator,
  CFURLRef							inStorageLocation,
  CFHTTPCookieStorageRef			  baseStorage,
  CFHTTPCookieStorageFilterProcPtr	filterCallback,
  CFHTTPCookieStorageFilterContext *  context)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageCreateInMemory()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageRef 
CFHTTPCookieStorageCreateInMemory(
  CFAllocatorRef		   inAllocator,
  CFHTTPCookieStorageRef   baseStorage)					   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageCreateFromFile()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageRef 
CFHTTPCookieStorageCreateFromFile(
  CFAllocatorRef		   inAllocator,
  CFURLRef				 inStorageLocation,
  CFHTTPCookieStorageRef   baseStorage)					   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageCreateArchive()
 *  
 */
CFN_EXPORT CFArrayRef 
CFHTTPCookieStorageCreateArchive(
  CFAllocatorRef		   inAllocator,
  CFHTTPCookieStorageRef   inStorage)						 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageCreateFromArchive()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageRef 
CFHTTPCookieStorageCreateFromArchive(
  CFAllocatorRef   inAllocator,
  CFArrayRef	   inArchive)								 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageScheduleWithRunLoop()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageScheduleWithRunLoop(
  CFHTTPCookieStorageRef   inStorage,
  CFRunLoopRef			 inRunloop,
  CFStringRef			  inRunloopMode)					 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageUnscheduleFromRunLoop()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageUnscheduleFromRunLoop(
  CFHTTPCookieStorageRef   inStorage,
  CFRunLoopRef			 inRunloop,
  CFStringRef			  inRunloopMode)					 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageGetBaseStorage()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageRef 
CFHTTPCookieStorageGetBaseStorage(CFHTTPCookieStorageRef inStorage) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageGetCookieAcceptPolicy()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageAcceptPolicy 
CFHTTPCookieStorageGetCookieAcceptPolicy(CFHTTPCookieStorageRef inCookieStorage) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageSetCookieAcceptPolicy()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageSetCookieAcceptPolicy(
  CFHTTPCookieStorageRef			inCookieStorage,
  CFHTTPCookieStorageAcceptPolicy   inCookieAcceptPolicy)	 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageCopyCookiesForURL()
 *  
 */
CFN_EXPORT CFArrayRef 
CFHTTPCookieStorageCopyCookiesForURL(
  CFHTTPCookieStorageRef   inCookieStorage,
  CFURLRef				 inURL,
  Boolean				  sendSecureCookies)				 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageSetCookie()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageSetCookie(
  CFHTTPCookieStorageRef   inCookieStorage,
  CFHTTPCookieRef		  inCookie)						  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageSetCookies()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageSetCookies(
  CFHTTPCookieStorageRef   inCookieStorage,
  CFArrayRef			   inCookies,
  CFURLRef				 inURL,
  CFURLRef				 inMainDocumentURL)				 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageCopyCookies()
 *  
 */
CFN_EXPORT CFArrayRef 
CFHTTPCookieStorageCopyCookies(CFHTTPCookieStorageRef inCookieStorage) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageDeleteCookie()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageDeleteCookie(
  CFHTTPCookieStorageRef   inCookieStorage,
  CFHTTPCookieRef		  inCookie)						  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageDeleteAllCookies()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageDeleteAllCookies(CFHTTPCookieStorageRef inCookieStorage) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageSyncStorageNow()
 *  
 */
CFN_EXPORT void
CFHTTPCookieStorageSyncStorageNow(CFHTTPCookieStorageRef inStorage) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFHTTPCookieStorageSetCookiesWithResponseHeaderFields()
 *  
 */
CFN_EXPORT void 
_CFHTTPCookieStorageSetCookiesWithResponseHeaderFields(
  CFHTTPCookieStorageRef			inCookieStorage,
  CFURLRef						  inURL,
  CFDictionaryRef				   headerFields,
  CFURLRef						  inPolicyURL,
  CFHTTPCookieStorageAcceptPolicy   inCookieAcceptPolicy)	 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFHTTPCookieStorageCopyRequestHeaderFieldsForURL()
 *  
 */
CFN_EXPORT CFDictionaryRef 
_CFHTTPCookieStorageCopyRequestHeaderFieldsForURL(
  CFAllocatorRef		   inAllocator,
  CFHTTPCookieStorageRef   inCookieStorage,
  CFURLRef				 inRequestURL)					  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 * CFHTTPCookie_domainMatches()
 * *very private, just for testing*
 */
CFN_EXPORT Boolean
CFHTTPCookie_domainMatches(
  CFHTTPCookieRef cookie, 
  CFURLRef inOriginURL)						  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

	
/*
 * CFHTTPCookieIsSecure()
 *
 * cookies marked as secure should only be sent via secure connections
 * and should not go to JavaScript applications.
 */
CFN_EXPORT Boolean
CFHTTPCookieIsSecure(
  CFHTTPCookieRef cookie)					 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);
	
/* CFHTTPCookieIsHTTPOnly()
 *
 * cookies marked as httponly should only be sent via http or secure connections
 * and should not go to JavaScript applications.
 */
CFN_EXPORT Boolean
CFHTTPCookieIsHTTPOnly(
  CFHTTPCookieRef cookie)					__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

	
/* _CFHTTPCookieStorageFlushCookieStores
 *
 * spi to _really_ flush all of the cookie storages to disk
 * and remove any in-memory cached cookie storages.
 * (for testing purposes mostly)
 */
CFN_EXPORT void
_CFHTTPCookieStorageFlushCookieStores()		__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_3_0);

	
/*
 * _CFHTTPCookieStorageSetDefaultLocation
 *
 * spi to change the cookie storage location.
 *  must be called before any connections are created, very un threadsafe.
 */
CFN_EXPORT void 
_CFHTTPCookieStorageSetDefaultLocation(CFURLRef newDefaultLocation)		__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_3_0);
	
#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __CFHTTPCOOKIESPRIV__ */

