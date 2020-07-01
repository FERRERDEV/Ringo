#pragma once

// Platforms
#ifdef RG_PLATFORM_WINDOWS
	#ifdef RG_LINK_DLL
		#ifdef RG_BUILD_DLL
			#define RINGO_API __declspec(dllexport)
		#else
			#define RINGO_API __declspec(dllimport)
		#endif
	#else
		#define RINGO_API
	#endif
#else
	#error Ringo only supports Windows!
#endif

// Asserts
#ifdef RG_ENABLE_ASSERTS
#define RG_ASSERT(x, ...) { if(!(x)) { RG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define RG_ENGINE_ASSERT(x, ...) { if(!(x)) { RG_ENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define RG_ASSERT(x, ...)
#define RG_ENGINE_ASSERT(x, ...)
#endif

// Events bus
#define BIT(x) (1 << x)