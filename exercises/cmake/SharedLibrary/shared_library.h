#pragma once

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

DLLEXPORT void Init();
DLLEXPORT void Release();
DLLEXPORT int SharedFoo();