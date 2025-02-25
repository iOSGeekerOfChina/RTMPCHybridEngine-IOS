#ifndef __RTMP_C_COMMON_H__
#define __RTMP_C_COMMON_H__
#include "LIV_Export.h"

typedef enum RTMPCVideoMode
{
	RTMPC_Video_HH = 0,
    RTMPC_Video_Low,
    RTMPC_Video_SD,
    RTMPC_Video_QHD,
    RTMPC_Video_HD,
    RTMPC_Video_720P,
    RTMPC_Video_1080P,
    RTMPC_Video_2K,
	RTMPC_Video_4K,
}RTMPCVideoMode;

typedef enum RTMPCScreenOrientation{
	RTMPC_SCRN_Portrait = 0,
	RTMPC_SCRN_LandscapeRight,
    RTMPC_SCRN_PortraitUpsideDown,
    RTMPC_SCRN_LandscapeLeft
}RTMPCScreenOrientation;

typedef enum RTMPMixVideoType
{
	RTMP_MXV_NULL = 0,
	RTMP_MXV_MAIN,
	RTMP_MXV_B_LEFT, 
	RTMP_MXV_B_RIGHT,
	RTMP_MXV_CUSTOM,
}RTMPMixVideoType;

typedef enum RTMPNetAdjustMode
{
	RTMP_NA_Nor	= 0,		// Normal
	RTMP_NA_Fast,			// When network is bad, we will drop some video frame.
	RTMP_NA_AutoBitrate		// When network is bad, we will adjust video bitrate to match.
    
}RTMPNetAdjustMode;


#ifdef WIN32
#include <string>
typedef void(*HttpAsyncCallback)(void*pUserData, int code, const char*pContent);
LIV_API void* HttpAsyncGetRequest(const char * strHostName, short sPort, const char * strUrl, int timeout/*seconds*/, void*userdata, HttpAsyncCallback callback);
LIV_API void HttpAsyncClose(void* handle);
LIV_API int  GenRandomString(char*buf, int len);
LIV_API void GetDrive(char*drive);
LIV_API void MKDir(const char* filePath);
LIV_API bool DirExist(const char* filePath);
LIV_API bool FileExist(const char* filePath);
LIV_API void DeleteDir(const char* filePath);
LIV_API void DeleteFile(const char* filePath);
LIV_API void GetHttpUrl(const char* url, std::string&strHost, int&port, std::string&path);
#endif

#endif	// __RTMP_C_COMMON_H__
