#include "albedolog_backend.h"

#include <spdlog/common.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <filesystem>

namespace Albedo {
namespace log
{

	Backend::Backend()
	{
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
#ifndef NDEBUG // Debug
        console_sink->set_level(spdlog::level::debug);
#else
        console_sink->set_level(spdlog::level::warn);
#endif
        auto log_file = std::filesystem::current_path().append("trace.log").string();
        auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(log_file, true);
        file_sink->set_level(spdlog::level::trace);

        m_logger = new spdlog::logger("system", { console_sink, file_sink });
        m_logger->set_level(spdlog::level::debug);
        m_logger->set_pattern("[%^%l%$] [%Y-%m-%d %H:%M:%S] %v");
	}

    Backend::~Backend()
    {
        m_logger->flush();
        spdlog::drop_all();
        delete this->m_logger;
    }

}} // namespace Albedo::log