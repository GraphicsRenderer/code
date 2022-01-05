#pragma once

#include "config.h"

#include <spdlog/spdlog.h>
#define LogInfo spdlog::info
#define LogError spdlog::error
#define LogWarn spdlog::warn
#define LogDebug spdlog::debug

inline void LogEnableBacktrace() { spdlog::enable_backtrace(32); }

inline void LogDumpBacktrace() { spdlog::dump_backtrace(); }

void InitLogger() {
  spdlog::set_pattern("[%H:%M:%S %z] [%^%L%$] [thread %t] %v");
  spdlog::set_level(spdlog::level::info);
}