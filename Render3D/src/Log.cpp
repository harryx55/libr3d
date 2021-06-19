#include "pch.h"
#include "Log.h"


namespace R3D
{
	std::shared_ptr<spdlog::logger> Log::Logger;
	void Log::Init()
	{
		std::vector<spdlog::sink_ptr> log;
		log.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		log.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Render 3D", true));

		log[0]->set_pattern("%^[%T] %n: %v%$");
		log[1]->set_pattern("[%T] [%l] %n: %v");

		Logger = std::make_shared<spdlog::logger>("Render 3D", begin(log), end(log));

		spdlog::register_logger(Logger);
		Logger->set_level(spdlog::level::trace);
		Logger->flush_on(spdlog::level::trace);
	}
}