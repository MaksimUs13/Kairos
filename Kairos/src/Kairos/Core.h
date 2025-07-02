#pragma once

#ifdef KR_PLATFORM_WINDOWS
#ifdef KR_BUILD_DLL
#define KAIROS_API __declspec(dllexport)
#else 
#define KAIROS_API __declspec(dllimport)
#endif
#else
#error Kairos only supports Windows!
#endif
