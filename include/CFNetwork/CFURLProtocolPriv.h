/*
	 File:	   CFNetwork/CFURLProtocolPriv.h
 
	 Contains:   CFType URL protocol header
 
	 Copyright:  Copyright (c) 2001-2008, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLPROTOCOLPRIV__
#define __CFURLPROTOCOLPRIV__

#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
#endif

#ifndef __COREFOUNDATION__
#include <CoreFoundation/CoreFoundation.h>
#endif

#ifndef __CFURLREQUESTPRIV__
#include <CFNetwork/CFURLRequestPriv.h>
#endif

#ifndef __CFURLRESPONSEPRIV__
#include <CFNetwork/CFURLResponsePriv.h>
#endif

#ifndef __CFURLAUTHCHALLENGEPRIV__
#include <CFNetwork/CFURLAuthChallengePriv.h>
#endif

#ifndef __CFURLCREDENTIALPRIV__
#include <CFNetwork/CFURLCredentialPriv.h>
#endif

#ifndef __CFURLCACHEPRIV__
#include <CFNetwork/CFURLCachePriv.h>
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


/*
 *  CFURLProtocol
 *  
 *  Discussion:
 *	CFURLProtocol is a CFType that manages the download of a
 *	CFURLRequest, producing a CFURLResponse and data
 */
typedef struct _CFURLProtocol*	CFURLProtocolRef;
/*
   Need to consider something like this, so we can confirm the final request before transmission
   typedef extern CFURLRequestRef (*CFURLProtocolWillSendRequestCallback)(CFURLProtocolRef prot, CFURLRequestRef newRequest, Boolean *shouldHalt, const void *client); 
*/
typedef CALLBACK_API_C( void , CFURLProtocolWasRedirectedCallback )(CFURLProtocolRef prot, CFURLRequestRef newRequest, CFURLResponseRef redirectResponse, const void *client);
typedef CALLBACK_API_C( void , CFURLProtocolCacheResponseIsValidCallback )(CFURLProtocolRef prot, CFCachedURLResponseRef cachedResponse, const void *client);
typedef CALLBACK_API_C( void , CFURLProtocolDidReceiveResponseCallback )(CFURLProtocolRef prot, CFURLResponseRef response, const void *client);
typedef CALLBACK_API_C( void , CFURLProtocolDidLoadDataCallback )(CFURLProtocolRef prot, CFDataRef data, SInt64 originalEncodedLength, const void *client);
typedef CALLBACK_API_C( void , CFURLProtocolDidSendBodyDataCallback )(CFURLProtocolRef prot, CFIndex bytesWritten, CFIndex totalBytesWritten, CFIndex totalBytesExpectedToWrite, const void *client);
typedef CALLBACK_API_C( void , CFURLProtocolDidFinishLoadingCallback )(CFURLProtocolRef prot, const void *client);
typedef CALLBACK_API_C( void , CFURLProtocolDidFailCallbackV0 )(CFURLProtocolRef prot, CFStreamError err, const void *client);
typedef CALLBACK_API_C( void , CFURLProtocolDidFailCallback )(CFURLProtocolRef prot, CFErrorRef err, const void *client);
typedef CALLBACK_API_C( void , CFURLProtocolDidReceiveAuthenticationChallengeCallback )(CFURLProtocolRef prot, CFURLAuthChallengeRef challenge, const void *client);
struct CFURLProtocolClient {
  CFIndex			 version;				/* Should be 1; if it is 0, the v0 version of the didFail callback is assumed*/
  const void *		client;

											  /* Memory management for the client pointer*/
  CFAllocatorRetainCallBack  retain;
  CFAllocatorReleaseCallBack  release;
  CFAllocatorCopyDescriptionCallBack  copyDescription;

											  /* Called as the protocol is processed*/
  CFURLProtocolWasRedirectedCallback  wasRedirected;
  CFURLProtocolCacheResponseIsValidCallback  cacheResponseIsValid;
  CFURLProtocolDidReceiveResponseCallback  didReceiveResponse;
  CFURLProtocolDidLoadDataCallback  didLoadData;
  CFURLProtocolDidFinishLoadingCallback  didFinishLoading;
  CFURLProtocolDidFailCallback  didFail;
  CFURLProtocolDidReceiveAuthenticationChallengeCallback  didReceiveAuthenticationChallenge;
  CFURLProtocolDidSendBodyDataCallback didSendBodyData;
};

typedef struct CFURLProtocolClient	  CFURLProtocolClient;
/*
 *  CFURLProtocolGetTypeID()
 *  
 */
CFN_EXPORT CFTypeID 
CFURLProtocolGetTypeID(void)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* "Class" functions*/
/*
 *  CFURLProtocolCanHandleRequest()
 *  
 */
CFN_EXPORT Boolean 
CFURLProtocolCanHandleRequest(CFURLRequestRef request)		__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLProtocolCreateCanonicalRequest()
 *  
 */
CFN_EXPORT CFURLRequestRef 
CFURLProtocolCreateCanonicalRequest(
  CFAllocatorRef	alloc,
  CFURLRequestRef   request)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLProtocolRequestsAreCacheEquivalent()
 *  
 */
CFN_EXPORT Boolean 
CFURLProtocolRequestsAreCacheEquivalent(
  CFURLRequestRef   request1,
  CFURLRequestRef   request2)								 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Creating and using CFURLProtocol instances*/
/*
 *  CFURLProtocolCreate()
 *  
 */
CFN_EXPORT CFURLProtocolRef 
CFURLProtocolCreate(
  CFAllocatorRef		   alloc,
  CFURLRequestRef		  request,
  CFCachedURLResponseRef   cachedResponse,
  CFURLProtocolClient *	client)							__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLProtocolGetClient()
 *  
 */
CFN_EXPORT CFURLProtocolClient * 
CFURLProtocolGetClient(CFURLProtocolRef prot)				 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLProtocolGetRequest()
 *  
 */
CFN_EXPORT CFURLRequestRef 
CFURLProtocolGetRequest(CFURLProtocolRef prot)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLProtocolGetCachedResponse()
 *  
 */
CFN_EXPORT CFCachedURLResponseRef 
CFURLProtocolGetCachedResponse(CFURLProtocolRef prot)		 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLProtocolScheduleWithRunLoop()
 *  
 */
CFN_EXPORT void 
CFURLProtocolScheduleWithRunLoop(
  CFURLProtocolRef   prot,
  CFRunLoopRef	   runLoop,
  CFStringRef		runLoopMode)							 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLProtocolUnscheduleFromRunLoop()
 *  
 */
CFN_EXPORT void 
CFURLProtocolUnscheduleFromRunLoop(
  CFURLProtocolRef   prot,
  CFRunLoopRef	   runLoop,
  CFStringRef		runLoopMode)							 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
   Do not use!  This is being staged out; use CFURLProtocolCopySchedulingArray, below, instead.
   Once CFSchedulingSet is available in CoreFoundation, there will be a scheduling set variant instead.
*/
/*
 *  CFURLProtocolGetSchedulingArray()
 *  
 */
CFN_EXPORT CFArrayRef 
CFURLProtocolGetSchedulingArray(CFURLProtocolRef prot)		__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLProtocolCopySchedulingArray()
 *  
 */
CFN_EXPORT CFArrayRef 
CFURLProtocolCopySchedulingArray(CFURLProtocolRef prot)	   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLProtocolCachedResponseIsValid()
 *  
 */
CFN_EXPORT Boolean 
_CFURLProtocolCachedResponseIsValid(CFURLProtocolRef prot)	__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLProtocolStartLoad()
 *  
 */
CFN_EXPORT void 
CFURLProtocolStartLoad(CFURLProtocolRef prot)				 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLProtocolCancelLoad()
 *  
 */
CFN_EXPORT void 
CFURLProtocolCancelLoad(CFURLProtocolRef prot)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLProtocolHaltLoad()
 *  
 */
CFN_EXPORT void 
CFURLProtocolHaltLoad(CFURLProtocolRef prot)				  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLProtocolResumeLoad()
 *  
 */
CFN_EXPORT void 
CFURLProtocolResumeLoad(CFURLProtocolRef prot)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
   Challenge must be the last authentication challenge sent from the protocol to its client; you cannot pre-emptively set a credential in the absence of a challenge
   Pass null credentials to continue without any credentials at all. 
*/
/*
 *  CFURLProtocolUseCredential()
 *  
 */
CFN_EXPORT void 
CFURLProtocolUseCredential(
  CFURLProtocolRef		prot,
  CFURLCredentialRef	  creds,
  CFURLAuthChallengeRef   challenge)						  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Informs the protocol that it is a download and should use download I/O characteristics*/
/*
 *  _CFURLProtocolSetIsDownload()
 *  
 */
CFN_EXPORT void 
_CFURLProtocolSetIsDownload(
  CFURLProtocolRef   prot,
  Boolean			isDownload)							  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



typedef CALLBACK_API_C( void , CFURLProtocolInstanceScheduleCallback )(CFURLProtocolRef protocol, CFRunLoopRef rl, CFStringRef rlMode, const void *info);
typedef CALLBACK_API_C( void , CFURLProtocolInstanceUnscheduleCallback )(CFURLProtocolRef protocol, CFRunLoopRef rl, CFStringRef rlMode, const void *info);
typedef CALLBACK_API_C( void , CFURLProtocolInstanceStartCallback )(CFURLProtocolRef protocol, const void *info);
typedef CALLBACK_API_C( void , CFURLProtocolInstanceStopCallback )(CFURLProtocolRef protocol, const void *info);
typedef CALLBACK_API_C( void , CFURLProtocolInstanceHaltCallback )(CFURLProtocolRef protocol, const void *info);
typedef CALLBACK_API_C( void , CFURLProtocolInstanceResumeCallback )(CFURLProtocolRef protocol, const void *info);
typedef CALLBACK_API_C( Boolean , CFURLProtocolInstanceCacheResponseIsValidCallback )(CFURLProtocolRef protocol, const void *info);
typedef CALLBACK_API_C( void , CFURLProtocolInstanceUseCredentialCallback )(CFURLProtocolRef protocol, CFURLCredentialRef creds, CFURLAuthChallengeRef challenge, const void *info);
typedef CALLBACK_API_C( void , CFURLProtocolInstanceSetIsDownload )(CFURLProtocolRef protocol, Boolean forDownload, const void *info);
typedef CALLBACK_API_C( void , CFURLProtocolInstanceSetConnectionProperties )(CFURLProtocolRef protocol, CFDictionaryRef urlConnectionProperties, const void *info);
struct CFURLProtocolInstanceCallbacks {
  CFIndex			 version;				/* Should be 2; 1 does not have setConnectionProperties ; version 0 does not have the setIsForDownload callback*/

											  /* Memory management for the info pointer*/
  CFAllocatorRetainCallBack  retain;
  CFAllocatorReleaseCallBack  release;
  CFAllocatorCopyDescriptionCallBack  copyDescription;
  CFURLProtocolInstanceScheduleCallback  schedule;
  CFURLProtocolInstanceUnscheduleCallback  unschedule;

  CFURLProtocolInstanceStartCallback  start;
  CFURLProtocolInstanceStopCallback  stop;

  CFURLProtocolInstanceHaltCallback  halt;
  CFURLProtocolInstanceResumeCallback  resume;

											  /* If the protocol instance never issues authentication challenges, it may set this callback to NULL*/
  CFURLProtocolInstanceUseCredentialCallback  useCredential;

  CFURLProtocolInstanceCacheResponseIsValidCallback  cacheResponseIsValid;

  CFURLProtocolInstanceSetIsDownload  setIsDownload; /* added starting with version 1*/
  CFURLProtocolInstanceSetConnectionProperties  setConnectionProperties; /* added starting with version 2*/
};
typedef struct CFURLProtocolInstanceCallbacks CFURLProtocolInstanceCallbacks;
typedef CALLBACK_API_C( Boolean , CFURLProtocolImplCanHandleRequestCallback )(CFURLRequestRef request, const void *info);
typedef CALLBACK_API_C( CFURLRequestRef , CFURLProtocolImplCreateCanonicalRequestCallback )(CFAllocatorRef alloc, CFURLRequestRef request, const void *info);
typedef CALLBACK_API_C( Boolean , CFURLProtocolImplRequestsAreCacheEquivalentCallback )(CFURLRequestRef request1, CFURLRequestRef request2, const void *info);
typedef CALLBACK_API_C( void *, CFURLProtocolImplProtocolInstanceForProtocolCallback )(CFURLProtocolRef protocol, const CFURLProtocolInstanceCallbacks **callbacks, const void *info);
struct CFURLProtocolImplementation_V0 {
  CFIndex			 version;				/* Should be 0*/
  const void *		info;

											  /* Memory management for the info pointer*/
  CFAllocatorRetainCallBack  retain;
  CFAllocatorReleaseCallBack  release;
  CFAllocatorCopyDescriptionCallBack  copyDescription;

  CFURLProtocolImplCanHandleRequestCallback  canHandleRequest;
  CFURLProtocolImplCreateCanonicalRequestCallback  createCanonicalRequest;
  CFURLProtocolImplRequestsAreCacheEquivalentCallback  requestsAreCacheEquivalent;
  CFURLProtocolImplProtocolInstanceForProtocolCallback  protocolInstanceForProtocol;
};
typedef struct CFURLProtocolImplementation_V0 CFURLProtocolImplementation;
/*
 *  CFURLProtocolRegisterImplementation()
 *  
 */
CFN_EXPORT void 
CFURLProtocolRegisterImplementation(CFURLProtocolImplementation * impl) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLProtocolUnregisterImplementation()
 *  
 */
CFN_EXPORT void 
CFURLProtocolUnregisterImplementation(CFURLProtocolImplementation * impl) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Protocol implementations should use these to send messages to the client*/
/*
 *  _CFURLProtocolSendWasRedirectedCallback()
 *  
 */
CFN_EXPORT void 
_CFURLProtocolSendWasRedirectedCallback(
  CFURLProtocolRef   prot,
  CFURLRequestRef	newRequest,
  CFURLResponseRef   redirectResponse)						__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLProtocolSendCacheResponseIsValidCallback()
 *  
 */
CFN_EXPORT void 
_CFURLProtocolSendCacheResponseIsValidCallback(
  CFURLProtocolRef		 prot,
  CFCachedURLResponseRef   cachedResponse)					__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLProtocolSendDidReceiveResponseCallback()
 *  
 */
CFN_EXPORT void 
_CFURLProtocolSendDidReceiveResponseCallback(
  CFURLProtocolRef   prot,
  CFURLResponseRef   response)								__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLProtocolSendDidLoadDataCallback()
 *  
 */
CFN_EXPORT void 
_CFURLProtocolSendDidLoadDataCallback(
  CFURLProtocolRef   prot,
  CFDataRef		  data,
  SInt64			 originalEncodedLength)				   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLProtocolSendDidFinishLoadingCallback()
 *  
 */
CFN_EXPORT void 
_CFURLProtocolSendDidFinishLoadingCallback(CFURLProtocolRef prot) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLProtocolSendDidFailCallback()
 *  
 */
CFN_EXPORT void 
_CFURLProtocolSendDidFailCallback(
  CFURLProtocolRef   prot,
  CFErrorRef		 err)									 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLProtocolSendDidReceiveAuthenticationChallengeCallback()
 *  
 */
CFN_EXPORT void 
_CFURLProtocolSendDidReceiveAuthenticationChallengeCallback(
  CFURLProtocolRef		prot,
  CFURLAuthChallengeRef   challenge)						  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Used by CFHTTPProtocol, Foundation and WebCore to construct the correct headers*/
/*
 *  _CFNetworkCopyPreferredLanguageCode()
 *  
 */
CFN_EXPORT CFStringRef 
_CFNetworkCopyPreferredLanguageCode(void)					 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __CFURLPROTOCOLPRIV__ */

