#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Ringo {

	class RINGO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_EngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ApplicationLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_ApplicationLogger;
	};

}

// Engine log macros
#define RG_ENGINE_TRACE(...)	::Ringo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RG_ENGINE_INFO(...)		::Ringo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RG_ENGINE_WARNING(...)	::Ringo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RG_ENGINE_ERROR(...)	::Ringo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RG_ENGINE_CRITICAL(...)	::Ringo::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Application log macros
#define RG_TRACE(...)			::Ringo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RG_INFO(...)			::Ringo::Log::GetClientLogger()->info(__VA_ARGS__)
#define RG_WARNING(...)			::Ringo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RG_ERROR(...)			::Ringo::Log::GetClientLogger()->error(__VA_ARGS__)
#define RG_CRITICAL(...)		::Ringo::Log::GetClientLogger()->critical(__VA_ARGS__)