#pragma once

#include <spdlog/spdlog.h>

#include "utility.h"

namespace SoftwareRenderer {
FUNC_ALISE(LogInfo, spdlog::info);
FUNC_ALISE(LogError, spdlog::error);
FUNC_ALISE(LogWarn, spdlog::warn);
FUNC_ALISE(LogDebug, spdlog::debug);

inline void LogEnableBacktrace() { spdlog::enable_backtrace(32); }

inline void LogDumpBacktrace() { spdlog::dump_backtrace(); }

inline void InitLogger()
{
    spdlog::set_pattern("[%H:%M:%S %z] [%^%L%$] [thread %t] %v");
    spdlog::set_level(spdlog::level::info);
}
} // namespace SoftwareRenderer
