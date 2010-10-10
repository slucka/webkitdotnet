/*
	 File:	   CFNetwork/CFURLConnectionPriv.h
 
	 Contains:   CFType URL Connection header
 
	 Copyright:  Copyright (c) 2001-2008, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLCONNECTIONPRIV__
#define __CFURLCONNECTIONPRIV__

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

/* This is only needed for the stubs of CFURLAuthenticationChallenge and CFURLCachedResponse; it should be removed when those objects come available. */
#ifndef __CFURLPROTOCOLPRIV__
#include <CFNetwork/CFURLProtocolPriv.h>
#endif

#ifndef __CFURLAUTHCHALLENGEPRIV__
#include <CFNetwork/CFURLAuthChallengePriv.h>
#endif

#ifndef __CFURLCREDENTIALPRIV__
#include <CFNetwork/CFURLCredentialPriv.h>
#endif


/* Provide a compiler flag folks can check for to determine which version of the callbacks are the "default" */
#define ERRORS_AS_CFERRORS

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
 *  CFURLConnection
 *  
 *  Discussion:
 *	CFURLConnection is a CFType that represents a download attempt of
 *	a CFURLRequest.  CFURLConnection is inherently asynchronous,
 *	although a synchronous API does exist.  CFURLConnections are
 *	created from a request and a client.  The request describes the
 *	download to be attempted; the client is the object contacted as
 *	the download progresses. which It is used by CFURLConnection and
 *	CFURLDownload.
 */
typedef struct _CFURLConnection*		CFURLConnectionRef;
typedef CALLBACK_API_C( CFURLRequestRef , CFURLConnectionWillSendRequestCallback )(CFURLConnectionRef conn, CFURLRequestRef request, CFURLResponseRef redirectionResponse, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidReceiveResponseCallback )(CFURLConnectionRef conn, CFURLResponseRef response, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidReceiveDataCallback )(CFURLConnectionRef conn, CFDataRef data, CFIndex originalLength, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidStopBufferingDataCallback )(CFURLConnectionRef conn, CFDataRef bufferedData, CFIndex originalLength, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidFinishLoadingCallback )(CFURLConnectionRef conn, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidFailCallbackV0 )(CFURLConnectionRef conn, CFStreamError error, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidFailCallback )(CFURLConnectionRef conn, CFErrorRef error, const void *clientInfo);
typedef CALLBACK_API_C( CFCachedURLResponseRef , CFURLConnectionWillCacheResponseCallback )(CFURLConnectionRef conn, CFCachedURLResponseRef cachedResponse, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidReceiveAuthenticationChallengeCallback )(CFURLConnectionRef conn, CFURLAuthChallengeRef challenge, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidSendBodyDataCallback )(CFURLConnectionRef conn, CFIndex bytesWritten, CFIndex totalBytesWritten, CFIndex totalBytesExpectedToWrite, const void *clientInfo);
typedef CALLBACK_API_C( Boolean , CFURLConnectionShouldUseCredentialStorageCallback )(CFURLConnectionRef conn, const void *clientInfo);
typedef CALLBACK_API_C( CFReadStreamRef , CFURLConnectionNeedNewBodyStreamCallback )(CFURLConnectionRef conn, CFURLRequestRef request, const void *clientInfo);

struct CFURLConnectionClient_V0 {
  CFIndex			 version;				/* 0*/
  const void *		clientInfo;

  CFAllocatorRetainCallBack  retain;
  CFAllocatorReleaseCallBack  release;
  CFAllocatorCopyDescriptionCallBack  copyDescription;

  CFURLConnectionWillSendRequestCallback  willSendRequest; /* starting with v1, CFURLConnection will take ownership of the returned request.  Clients of CFURLConnection MUST retain the CFURLRequest passed to willSendRequest. */
  CFURLConnectionDidReceiveResponseCallback  didReceiveResponse;
  CFURLConnectionDidReceiveDataCallback  didReceiveData;
  CFURLConnectionDidStopBufferingDataCallback  didStopBuffering;
  CFURLConnectionDidFinishLoadingCallback  didFinishLoading;
  CFURLConnectionDidFailCallbackV0  didFail;
  CFURLConnectionWillCacheResponseCallback  willCacheResponse; /* starting with v1, CFURLConnection will take ownership of the returned cached response (i.e. this callback should return a reference to the returned object)*/
  CFURLConnectionDidReceiveAuthenticationChallengeCallback  didReceiveAuthenticationChallenge;
};
	
struct CFURLConnectionClient_V1 {
	CFIndex			 version;				/* 1 */
	const void *		clientInfo;
	
	CFAllocatorRetainCallBack  retain;
	CFAllocatorReleaseCallBack  release;
	CFAllocatorCopyDescriptionCallBack  copyDescription;
	
	CFURLConnectionWillSendRequestCallback  willSendRequest; /* starting with v1, CFURLConnection will take ownership of the returned request (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveResponseCallback  didReceiveResponse;
	CFURLConnectionDidReceiveDataCallback  didReceiveData;
	CFURLConnectionDidStopBufferingDataCallback  didStopBuffering;
	CFURLConnectionDidFinishLoadingCallback  didFinishLoading;
	CFURLConnectionDidFailCallback  didFail;
	CFURLConnectionWillCacheResponseCallback  willCacheResponse; /* starting with v1, CFURLConnection will take ownership of the returned cached response (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveAuthenticationChallengeCallback  didReceiveAuthenticationChallenge;
};

#define _CFURLConnectionClientV2Present 1
struct CFURLConnectionClient_V2 {
	CFIndex			 version;				/* 2 */
	const void *		clientInfo;
	
	CFAllocatorRetainCallBack  retain;
	CFAllocatorReleaseCallBack  release;
	CFAllocatorCopyDescriptionCallBack  copyDescription;
	
	CFURLConnectionWillSendRequestCallback  willSendRequest; /* starting with v1, CFURLConnection will take ownership of the returned request (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveResponseCallback  didReceiveResponse;
	CFURLConnectionDidReceiveDataCallback  didReceiveData;
	CFURLConnectionDidStopBufferingDataCallback  didStopBuffering;
	CFURLConnectionDidFinishLoadingCallback  didFinishLoading;
	CFURLConnectionDidFailCallback  didFail;
	CFURLConnectionWillCacheResponseCallback  willCacheResponse; /* starting with v1, CFURLConnection will take ownership of the returned cached response (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveAuthenticationChallengeCallback  didReceiveAuthenticationChallenge;
	CFURLConnectionDidSendBodyDataCallback didSendBodyData;		/* new for v2 */
};

#define _CFURLConnectionClientV3Present 1
struct CFURLConnectionClient_V3 {
	CFIndex			 version;				/* 3 */
	const void *		clientInfo;
	
	CFAllocatorRetainCallBack  retain;
	CFAllocatorReleaseCallBack  release;
	CFAllocatorCopyDescriptionCallBack  copyDescription;
	
	CFURLConnectionWillSendRequestCallback  willSendRequest; /* starting with v1, CFURLConnection will take ownership of the returned request (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveResponseCallback  didReceiveResponse;
	CFURLConnectionDidReceiveDataCallback  didReceiveData;
	CFURLConnectionDidStopBufferingDataCallback  didStopBuffering;
	CFURLConnectionDidFinishLoadingCallback  didFinishLoading;
	CFURLConnectionDidFailCallback  didFail;
	CFURLConnectionWillCacheResponseCallback  willCacheResponse; /* starting with v1, CFURLConnection will take ownership of the returned cached response (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveAuthenticationChallengeCallback  didReceiveAuthenticationChallenge;
	CFURLConnectionDidSendBodyDataCallback didSendBodyData;		/* new for v2 */
	CFURLConnectionShouldUseCredentialStorageCallback shouldUseCredentialStorage; /* new for v3 */
	CFURLConnectionNeedNewBodyStreamCallback needNewBodyStream; /* new for v3 */	
};

typedef struct CFURLConnectionClient_V0 CFURLConnectionClient_V0;
typedef struct CFURLConnectionClient_V1 CFURLConnectionClient_V1;
typedef struct CFURLConnectionClient_V2 CFURLConnectionClient_V2;
typedef struct CFURLConnectionClient_V3 CFURLConnectionClient_V3;
typedef CFURLConnectionClient_V3 CFURLConnecitonClientCurrent;


typedef struct CFURLConnectionClient_V1	CFURLConnectionClient; // this is for source compatiblity with existing clients...

/*
 *  CFURLConnectionGetTypeID()
 *  
 */
CFN_EXPORT CFTypeID 
CFURLConnectionGetTypeID(void)								__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionCreate()
 *  
 */
CFN_EXPORT CFURLConnectionRef 
CFURLConnectionCreate(
  CFAllocatorRef		   alloc,
  CFURLRequestRef		  request,
  CFURLConnectionClient *  client)							__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionScheduleWithRunLoop()
 *  
 */
CFN_EXPORT void 
CFURLConnectionScheduleWithRunLoop(
  CFURLConnectionRef   conn,
  CFRunLoopRef		 rl,
  CFStringRef		  mode)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionUnscheduleFromRunLoop()
 *  
 */
CFN_EXPORT void 
CFURLConnectionUnscheduleFromRunLoop(
  CFURLConnectionRef   conn,
  CFRunLoopRef		 rl,
  CFStringRef		  mode)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
   If you want the actual download work to take on a thread other than where the connection itself is scheduled, call these.  
   Otherwise, the download will take place wherever the connection itself has been scheduled
*/
/*
 *  CFURLConnectionScheduleDownloadWithRunLoop()
 *  
 */
CFN_EXPORT void 
CFURLConnectionScheduleDownloadWithRunLoop(
  CFURLConnectionRef   conn,
  CFRunLoopRef		 rl,
  CFStringRef		  mode)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionUnscheduleDownloadFromRunLoop()
 *  
 */
CFN_EXPORT void 
CFURLConnectionUnscheduleDownloadFromRunLoop(
  CFURLConnectionRef   conn,
  CFRunLoopRef		 rl,
  CFStringRef		  mode)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


#if defined(__WIN32__)
/*
 *  CFURLConnectionScheduleWithCurrentMessageQueue()
 *  
 */
CFN_EXPORT void 
CFURLConnectionScheduleWithCurrentMessageQueue(CFURLConnectionRef conn) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


#endif
/*
 *  CFURLConnectionStart()
 *  
 */
CFN_EXPORT void 
CFURLConnectionStart(CFURLConnectionRef conn)				 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionCancel()
 *  
 */
CFN_EXPORT void 
CFURLConnectionCancel(CFURLConnectionRef conn)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionHalt()
 *  
 */
CFN_EXPORT void 
CFURLConnectionHalt(CFURLConnectionRef conn)				  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionResume()
 *  
 */
CFN_EXPORT void 
CFURLConnectionResume(CFURLConnectionRef conn)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionUseCredential()
 *  
 */
CFN_EXPORT void 
CFURLConnectionUseCredential(
  CFURLConnectionRef	  conn,
  CFURLCredentialRef	  creds,
  CFURLAuthChallengeRef   challenge)						  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
   Synchronously sends the request and returns the data, plus the response and any error by-ref.  Caller must release the returned data, as well as 
   the response and error if they are requested.  No customization during the processing of the request is permitted.  
*/
/*
 *  CFURLConnectionSendSynchronousRequest()
 *  
 */
CFN_EXPORT CFDataRef 
CFURLConnectionSendSynchronousRequest(
  CFURLRequestRef	 request,
  CFURLResponseRef *  response,
  CFErrorRef *		err,
  CFTimeInterval	  timeout)								__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __CFURLCONNECTIONPRIV__ */

