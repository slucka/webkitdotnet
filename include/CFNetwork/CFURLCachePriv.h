/*
	 File:	   CFNetwork/CFURLCachePriv.h
 
	 Contains:   CFType URL Cache header
 
	 Copyright:  Copyright (c) 2001-2008, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLCACHEPRIV__
#define __CFURLCACHEPRIV__

#ifndef __CFURLREQUESTPRIV__
#include <CFNetwork/CFURLRequestPriv.h>
#endif

#ifndef __CFURLRESPONSEPRIV__
#include <CFNetwork/CFURLResponsePriv.h>
#endif



#include <Availability.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint on
#endif


/*
 *  CFURLCachePriv
 *  
 *  Discussion:
 *	CFURLCache is a CFType that represents a cache of URLs.
 */
typedef const struct _CFCachedURLResponse*  CFCachedURLResponseRef;
typedef const struct _CFURLCache*	   CFURLCacheRef;
/*
 *  CFURLCacheGetTypeID()
 *  
 */
CFN_EXPORT CFTypeID 
CFURLCacheGetTypeID(void)									 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseGetTypeID()
 *  
 */
CFN_EXPORT CFTypeID 
CFCachedURLResponseGetTypeID(void)							__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseCreateWithData()
 *  
 */
CFN_EXPORT CFCachedURLResponseRef 
CFCachedURLResponseCreateWithData(
  CFAllocatorRef	 alloc,
  CFURLResponseRef   response,
  CFDataRef		  data)									__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseCreateWithUserInfo()
 *  
 */
CFN_EXPORT CFCachedURLResponseRef 
CFCachedURLResponseCreateWithUserInfo(
  CFAllocatorRef			alloc,
  CFURLResponseRef		  response,
  CFDataRef				 data,
  CFPropertyListRef		 userInfo,
  CFURLCacheStoragePolicy   storagePolicy)					__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseGetWrappedResponse()
 *  
 */
CFN_EXPORT CFURLResponseRef 
CFCachedURLResponseGetWrappedResponse(CFCachedURLResponseRef cachedResponse) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseGetReceiverData()
 *  
 */
CFN_EXPORT CFDataRef 
CFCachedURLResponseGetReceiverData(CFCachedURLResponseRef cachedResponse) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseGetUserInfo()
 *  
 */
CFN_EXPORT CFPropertyListRef 
CFCachedURLResponseGetUserInfo(CFCachedURLResponseRef cachedResponse) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseGetStoragePolicy()
 *  
 */
CFN_EXPORT CFURLCacheStoragePolicy 
CFCachedURLResponseGetStoragePolicy(CFCachedURLResponseRef cachedResponse) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseSetStoragePolicy()
 *  
 */
CFN_EXPORT void 
CFCachedURLResponseSetStoragePolicy(
  CFCachedURLResponseRef	cachedResponse,
  CFURLCacheStoragePolicy   storagePolicy)					__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheSharedURLCache()
 *  
 */
CFN_EXPORT CFURLCacheRef 
CFURLCacheSharedURLCache(void)								__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

/*
 *  CFURLCacheCopySharedURLCache()
 *  
 */
CFN_EXPORT CFURLCacheRef 
CFURLCacheCopySharedURLCache(void)								__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_3_0);
	
/*
 *  CFURLCacheSetSharedURLCache()
 *  
 */
CFN_EXPORT void 
CFURLCacheSetSharedURLCache(CFURLCacheRef cache)			  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheCreate()
 *  
 */
CFN_EXPORT CFURLCacheRef 
CFURLCacheCreate(
  CFAllocatorRef   alloc,
  CFIndex		  memoryCapacity,
  CFIndex		  diskCapacity,
  CFStringRef	  path)									  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheCopyResponseForRequest()
 *  
 */
CFN_EXPORT CFCachedURLResponseRef 
CFURLCacheCopyResponseForRequest(
  CFURLCacheRef	 cacheRef,
  CFURLRequestRef   request)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheAddCachedResponseForRequest()
 *  
 */
CFN_EXPORT void 
CFURLCacheAddCachedResponseForRequest(
  CFURLCacheRef			cacheRef,
  CFCachedURLResponseRef   cachedResponse,
  CFURLRequestRef		  request,
  CFTypeRef				nsCachedURLResponse)			   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheRemoveCachedResponseForRequest()
 *  
 */
CFN_EXPORT void 
CFURLCacheRemoveCachedResponseForRequest(
  CFURLCacheRef	 cacheRef,
  CFURLRequestRef   request)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheRemoveAllCachedResponses()
 *  
 */
CFN_EXPORT void 
CFURLCacheRemoveAllCachedResponses(CFURLCacheRef cacheRef)	__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheMemoryCapacity()
 *  
 */
CFN_EXPORT CFIndex 
CFURLCacheMemoryCapacity(CFURLCacheRef cacheRef)			  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheDiskCapacity()
 *  
 */
CFN_EXPORT CFIndex 
CFURLCacheDiskCapacity(CFURLCacheRef cacheRef)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheSetMemoryCapacity()
 *  
 */
CFN_EXPORT void 
CFURLCacheSetMemoryCapacity(
  CFURLCacheRef   cacheRef,
  CFIndex		 memoryCapacity)							 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheSetDiskCapacity()
 *  
 */
CFN_EXPORT void 
CFURLCacheSetDiskCapacity(
  CFURLCacheRef   cacheRef,
  CFIndex		 diskCapacity)							   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheCurrentMemoryUsage()
 *  
 */
CFN_EXPORT CFIndex 
CFURLCacheCurrentMemoryUsage(CFURLCacheRef cacheRef)		  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheCurrentDiskUsage()
 *  
 */
CFN_EXPORT CFIndex 
CFURLCacheCurrentDiskUsage(CFURLCacheRef cacheRef)			__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFURLCACHEPRIV__ */

