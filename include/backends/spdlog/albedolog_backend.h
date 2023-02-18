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
            instance()->info(fmt, std::forward<Args>(args)...);
        }

        template <typename... Args>
        inline void error(format_string<Args...> fmt, Args&&... args)
        {
            instance()->error(fmt, std::forward<Args>(args)...);
        }

        template <typename... Args>
        inline void warn(format_string<Args...> fmt, Args&&... args)
        {
            instance()->warn(fmt, std::forward<Args>(args)...);
        }

        template <typename... Args>
        inline void critical(format_string<Args...> fmt, Args&&... args)
        {
            instance()->critical(fmt, std::forward<Args>(args)...);
        }

        spdlog::logger* operator->()
        {
            return this->m_logger;
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