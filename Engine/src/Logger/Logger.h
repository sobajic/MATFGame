#pragma once

#include <spdlog/spdlog.h>
#include <memory>

using externLogger_t = spdlog::logger;

namespace Engine {

    class Logger
    {
    public:
        static void Init();

        inline static externLogger_t& GetLogger() { return *ms_Logger; }
    private:
        inline static std::unique_ptr<externLogger_t> ms_Logger;
    };
}

#ifdef _DEBUG

#define LOG_CRITICAL(...) \
    do \
    { \
         \
    } \
    while (0)

#define LOG_ERROR(...) \
    do \
    { \
         \
    } \
    while (0)

#define LOG_WARNING(...) \
    do \
    { \
         \
    } \
    while (0)

#define LOG_INFO(...) \
    do \
    { \
         \
    } \
    while (0)

#define ASSERT(x, ...) \
    do \
    { \
        if(!(x)) \
        { \
             \
            __debugbreak(); \
        } \
    } \
    while (0)

#else  // NDEBUG

// These are the release mode definitions for the macros above.
#define LOG_CRITICAL(...)
#define LOG_ERROR(...)
#define LOG_WARNING(...)
#define LOG_INFO(...)
#define ASSERT(x, ...)

#endif  // !defined NDEBUG