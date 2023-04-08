#pragma once

#include <albedolog_backend.h>

namespace Albedo {
namespace log
{

    template <typename... Args>
    inline void info(format_string<Args...> fmt, Args&&... args)
    {
        Backend::instance().info(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    inline void error(format_string<Args...> fmt, Args&&... args)
    {
        Backend::instance().error(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    inline void warn(format_string<Args...> fmt, Args&&... args)
    {
        Backend::instance().warn(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    inline void debug(format_string<Args...> fmt, Args&&... args)
    {
        Backend::instance().debug(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    inline void critical(format_string<Args...> fmt, Args&&... args)
    {
        Backend::instance().critical(fmt, std::forward<Args>(args)...);
    }

}} // namespace Albedo::log