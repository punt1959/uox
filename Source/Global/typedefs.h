// 
// Created on:  6/4/21

#ifndef typedefs_h
#define typedefs_h
#include "ConfigOS.h"

#if PLATFORM == WINDOWS

typedef SOCKET  socket_desc ;
#define INVALID_DESC INVALID_SOCKET

#else

typedef int socket_desc ;
#define INVALID_DESC -1

#endif

#endif /* typedefs_h */
