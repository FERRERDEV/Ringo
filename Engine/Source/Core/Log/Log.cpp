#include <rgpch.h>
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Ringo {

	std::shared_ptr<spdlog::logger> Log::s_EngineLogger;
	std::shared_ptr<spdlog::logger> Log::s_ApplicationLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_EngineLogger = spdlog::stdout_color_mt("ENGINE");
		s_EngineLogger->set_level(spdlog::level::trace);

		s_ApplicationLogger = spdlog::stdout_color_mt("APPLICATION");
		s_ApplicationLogger->set_level(spdlog::level::trace);
	}

}