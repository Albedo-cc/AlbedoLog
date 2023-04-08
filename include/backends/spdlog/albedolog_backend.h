#pragma once

#include <spdlog/spdlog.h>

namespace Albedo {
namespace log
{
	template <typename... Args>
	using format_string = spdlog::format_string_t<Args...>;

    class Backend // Interface
    {
    public:
        template <typename... Args>
        inline void info(format_string<Args...> fmt, Args&&... args)
        {
            m_logger->info(fmt, std::forward<Args>(args)...);
        }

        template <typename... Args>
        inline void error(format_string<Args...> fmt, Args&&... args)
        {
            m_logger->error(fmt, std::forward<Args>(args)...);
        }

        template <typename... Args>
        inline void warn(format_string<Args...> fmt, Args&&... args)
        {
            m_logger->warn(fmt, std::forward<Args>(args)...);
        }

        template <typename... Args>
        inline void debug(format_string<Args...> fmt, Args&&... args)
        {
            m_logger->debug(fmt, std::forward<Args>(args)...);
        }

        template <typename... Args>
        inline void critical(format_string<Args...> fmt, Args&&... args)
        {
            m_logger->critical(fmt, std::forward<Args>(args)...);
        }

        static Backend& instance()
        {
            static Backend singleton{};
            return singleton;
        }

    protected:
        spdlog::logger* m_logger = nullptr;

    protected:
        Backend();
        ~Backend();
        Backend(const Backend&) = delete;
        Backend(Backend&&) = delete;
        Backend& operator=(const Backend&) = delete;
        Backend& operator=(Backend&&) = delete;
    };

}} // namespace Albedo::log