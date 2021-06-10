// 
// Created on:  6/3/21

#ifndef ConfigOS_h
#define ConfigOS_h

#include <cstdint>      // We need this if INTPRT_MAX and INT64_MAX

#define WINDOWS 	0
#define MACOS 	1
#define LINUX 	2
#define UNKNOWN	3

#define XSTR(x) STR(x)
#define STR(x) #x



#if defined(_WIN32)
//------------ Windows defines

#define PLATFORM WINDOWS
#define WIN32_LEAN_AND_MEAN  // Since we are using Winsock2

#if defined(_WIN64)	// JS Requires OS Strings
#define OS_STR "Win64"
#else
#define OS_STR "Win32"
#endif

#elif defined(__linux__)
//------------ Linux defines
#define PLATFORM LINUX

#define SOCKET int
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

#if INTPTR_MAX == INT64_MAX  // INPTR_MAX is defined in <stdint.h>
#define OS_STR "Linux64"
#else
#define OS_STR "Linux32"
#endif

#elif defined(__APPLE__)
//------------ Macos defines

#define PLATFORM MACOS

#define SOCKET int
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1


#if INTPTR_MAX == INT64_MAX
#define OS_STR "MacOS64"
#else
#define OS_STR "MacOS32"
#endif

#else
//------------ Unknown OS defines
#define PLATFORM UNKNOWN
#define OS_STR "Unknown"

#endif

#endif /* ConfigOS_h */
