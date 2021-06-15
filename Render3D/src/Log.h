#pragma once

#include "pch.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace R3D
{
	class Log
	{
	public:
		static void Init();
		__forceinline static auto GetLogger() { return Logger; }

	private:
		static std::shared_ptr<spdlog::logger> Logger;
	};
}

#define R3D_TRACE(...)	 ::R3D::Log::GetLogger()->trace(__VA_ARGS__)
#define R3D_ERROR(...)	 ::R3D::Log::GetLogger()->error(__VA_ARGS__)
#define R3D_INFO(...)	 ::R3D::Log::GetLogger()->info(__VA_ARGS__)
#define R3D_WARN(...)	 ::R3D::Log::GetLogger()->warn(__VA_ARGS__)
