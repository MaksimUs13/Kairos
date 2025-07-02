#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Kairos {

	class KAIROS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLoger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// core log macros
#define KR_CORE_TRACE(...)    ::Kairos::Log::GetCoreLoger()->trace(__VA_ARGS__)
#define KR_CORE_INFO(...)     ::Kairos::Log::GetCoreLoger()->info(__VA_ARGS__)
#define KR_CORE_WARN(...)     ::Kairos::Log::GetCoreLoger()->warn(__VA_ARGS__)
#define KR_CORE_ERROR(...)    ::Kairos::Log::GetCoreLoger()->error(__VA_ARGS__)
#define KR_CORE_FATAL(...)    ::Kairos::Log::GetCoreLoger()->fatal(__VA_ARGS__)

// client log macros
#define KR_TRACE(...)         ::Kairos::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KR_INFO(...)          ::Kairos::Log::GetClientLogger()->info(__VA_ARGS__)
#define KR_WARN(...)          ::Kairos::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KR_ERROR(...)         ::Kairos::Log::GetClientLogger()->error(__VA_ARGS__)
#define KR_FATAL(...)         ::Kairos::Log::GetClientLogger()->fatal(__VA_ARGS__)