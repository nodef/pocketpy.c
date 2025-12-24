#pragma once
#include "pocketpy/pocketpy.h"

#ifdef POCKETPY_IMPLEMENTATION
#ifdef _WIN32
#pragma comment(lib, "ws2_32.lib")
#endif
#include "pocketpy/pocketpy.c"
#endif
